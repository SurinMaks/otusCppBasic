#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

void consumer(std::mutex& mutex,
              std::condition_variable& condition_variable,
              bool& notificated,
              bool& done)
{
    while (true)
    {
        std::unique_lock<std::mutex> lck{mutex};

        if (done) {
            std::cout << "Consumer: Exiting...\n";
            break;
        }

        std::cout << "Waiting for task\n";

		/*
			Возможные проблемы:
			1. Утерянное пробуждение - ситуация, когда поток отправитель успевает послать
            оповещение до того, как получатель начинает его ожидать.
            condition_variable не хранит информацию о факте уведомления.

			 Решение: заводим переменную notificated, обязываем потребителя подтверждать получение.
			2. Ложное пробуждение (spurious wakeup) - пробуждение ожидающего потока, когда
            отправители никаких оповещений не посылали.
            Одна из причин - похищенное пробуждение: перед тем как пробужденный поток-адресат получает
             шанс запуститься, другой поток успевает вклиниться первым и начинает выполнение.

            Решение: используем предикат.
		*/
		/*
			Перед тем, как заснуть, condition_variable отпускает мьютех,
			 после пробуждения захватывает его обратно.
		*/
        condition_variable.wait(lck, [&notificated, &done]() {
            return notificated || done;
        });
		/* Аналог
			while (![&notificated, &done]() {return notificated || done;})
			{
				condition_variable.wait(lck);
			}
		*/

        // Имитация работы
        std::this_thread::sleep_for(1ms);

        // Подтверждаем, что уведомление было получено и обработано
        notificated = false;
        std::cout << "Task was finished\n";
    }
}

void producer(std::mutex& mutex,
              std::condition_variable& condition_variable,
              bool& notificated,
              bool& done,
              int num_notifications)
{
    for (int i = 0; i < num_notifications; ++i)
    {
        std::lock_guard<std::mutex> lck{mutex};
        std::cout << "Before wake up\n";
        // Общие данные должны находиться под mutex,
        //  даже если они имеют атомарный тип,
        //  иначе обновление переменной может быть неправильно синхронизироваться.
        notificated = true;
        condition_variable.notify_one(); // Уведомляем потребителя под защитой мьютекса
        std::cout << "After wake up\n";
    }

    // Завершаем работу
    {
        std::lock_guard<std::mutex> lck{mutex};
        done = true;
        condition_variable.notify_all(); // Уведомляем потребителя для выхода
    }
}

int main()
{
    std::mutex mutex;
    std::condition_variable condition_variable;
    bool notificated{false};
    bool done{false};

    const int num_notifications{5};

    std::thread thr1{consumer,
                     std::ref(mutex),
                     std::ref(condition_variable),
                     std::ref(notificated),
                     std::ref(done)};
    std::thread thr2{producer,
                     std::ref(mutex),
                     std::ref(condition_variable),
                     std::ref(notificated),
                     std::ref(done),
                     num_notifications};

    thr1.join();
    thr2.join();
}
