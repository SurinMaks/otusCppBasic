#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

/*
 Потокобезопасная очередь на основе связного списка с возможностью блокирующего ожидания данных.
*/
namespace list
{
constexpr static int productsCount = 1000;

/* Структура, которая объединяет указатель и мьютекс для его защиты. */
template<typename T>
struct WithMutex
{
    template<class TT>
    WithMutex(TT&& ptr): ptr{std::forward<TT>(ptr)} {}

    T ptr;
    std::mutex mutex;
};

/*
 Однонаправленный список.
 Каждый узел содержит значение и указатель на следующий узел.
 head и tail защищены отдельными мьютексами.
 Использует condition_variable для ожидания данных.
*/
template<typename T>
struct WaitingQueue
{

    WaitingQueue()
    /* Очередь создается с пустой нодой, это позволит корректно сделать первый push. */
        : head{new Node}, tail{head.ptr.get()}, m_stopped{false}
    {}

    /*  Блокирующее извлечение. */
    bool pop(T& entry)
    {
        /*  Условие пробуждения: очередь остановлена ИЛИ есть элементы */
        auto wakeUpCond = [this] () {
            return m_stopped || head.ptr.get() != getTailSafe();
        };

        /*
         Ждём!
         Используем мьютекс head, поэтому для работы с tail нужен мьютекс tail.
         Для это используем специальный метод getTailSafe.
        */
        std::unique_lock lck{head.mutex};
        m_conditional.wait(lck, wakeUpCond);

        if (m_stopped)
        {
            return false;
        }
        // Извлекаем задание
        entry = std::move(head.ptr->value);
        // Удаляем задание из очереди (удаляем головной узел)
        takeHeadUnsafe();
        return true;
    }

    /* Добавление задания в конец очереди. */
    template<typename TT>
    void push(TT&& value)
    {
        // Задания добавляются в конец, поэтому блокируем tail.
        std::lock_guard<std::mutex> lck{tail.mutex};

        if (!m_stopped)
        {
            // Добавляем значение в конец очереди.
            tail.ptr->value = std::forward<TT>(value);
            // Создаем новый конец очереди.
            tail.ptr->next.reset(new Node);
            // В текущий конец очереди добавляем указатель на новый конец очереди.
            tail.ptr = tail.ptr->next.get();
            m_conditional.notify_one();
        }
    }

    /* Оповещаем всех потребителей, что разблокировать их потоки. */
    void stop()
    {
        /* Предотвращаем dead lock: захватываем оба мьюьекса сразу */
        std::scoped_lock lock(head.mutex, tail.mutex);
        m_stopped = true;
        m_conditional.notify_all();
    }

private:
    struct Node
    {
        T value;
        std::unique_ptr<Node> next;
    };

    Node* getTailSafe()
    {
        /*
            Используем мьютекс, потому что параллельно может выполняться операция push(),
             которая изменяет tail.
        */
        std::lock_guard<std::mutex> lck{tail.mutex};
        return tail.ptr;
    }

    std::unique_ptr<Node> takeHeadUnsafe()
    {
        std::unique_ptr<Node> prevHead = std::move(head.ptr);
        head.ptr = std::move(prevHead->next);
        return prevHead;
    }

    /*
     Начало очереди, откуда берутся задания.
     Используем unique_ptr, чтобы руками не освобождать отработанные задания.
    */
    WithMutex<std::unique_ptr<Node>> head;
    /*
     Конец очереди, куда добавляются задания.
     Не используем unique_ptr, потому что ресурс из tail будет передан в head.
    */
    WithMutex<Node*> tail;
    // Уведомление о новых заданиях.
    std::condition_variable m_conditional;
    // Флaг оставновки добавления новых заданий.
    bool m_stopped;
};

using WorkQueue = WaitingQueue<int>;

void work_producer(WorkQueue& queue, std::atomic<bool>& stop_flag)
{
    for (int i = 0; i < productsCount; ++i)
    {
        // Добавляем новое значение в очередь.
        std::cout << "work_producer - put new value: " << i << '\n';
        if (!stop_flag)
        {
            queue.push(i);
        }
        else
        {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "work_producer - end of cycle\n";
}

void work_consumer(WorkQueue& queue)
{
    int value = 0;
    // Ожидаем возврата значения методом pop.
    // Потребитель работает до тех пор, пока pop возвращает значения.
    while (queue.pop(value))
    {
        std::cout << "work_consumer - pop new value: " << value << '\n';
    }
    std::cout << "work_consumer - end of cycle\n";
}

void example()
{
    std::atomic<bool> stop_flag{false};
    WorkQueue work_queue;

    std::cout << "Launch threads!\n";

    /* Запускаем один поток-производитель и два потока-потребителя. */
    std::thread work_producer_thread{
            work_producer,
            std::ref(work_queue),
            std::ref(stop_flag)
    };
    std::thread work_consumer_thread1{
            work_consumer,
            std::ref(work_queue)
    };
    std::thread work_consumer_thread2{
            work_consumer,
            std::ref(work_queue)
    };

    // Через 5 секунд устанавливаем флаг остановки.
    std::this_thread::sleep_for(std::chrono::seconds{5});
    std::cout << "Finish working!\n";
    stop_flag = true;

    // Вызываем stop() для разблокировки ждущих потоков.
    work_queue.stop();

    // Ожидаем завершение всех потоков.
    work_producer_thread.join();
    work_consumer_thread1.join();
    work_consumer_thread2.join();

    std::cout << "Finished!\n";
}
} // namespace list

int main()
{
    list::example();
}
