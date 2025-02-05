#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

constexpr static int productsCount = 1000;

namespace cv
{

/*
	Многопоточная очередь с использованием condition_variable для синхронизации производителя и потребителей.
	Эффективность очереди достигается использованием condition_variable, т.к. потоки не тратят CPU в ожидании.
*/
class Queue
{
  public:
	void push(int value)
	{
		std::unique_lock lock{mutex};
		queue.push(value);
		cv.notify_one();
	}

	bool pop(int &value)
	{
		std::unique_lock lock{mutex};
		// Ждём, пока
		// очередь не станет непустой
		// ИЛИ не будет установлен флаг stopped.
		cv.wait(lock, [this]() {
			return !queue.empty() || stopped;
		});

		bool noMore = queue.empty() && stopped;

		// Извлекаем значение из очереди, если она не пуста
		if (!queue.empty()) {
			value = queue.front();
			queue.pop();
		}
		return !noMore;
	}

	// Оповещаем все ждущие потоки, что разблокировать их
	void stop()
	{
		std::unique_lock lock{mutex};
		stopped = true;
		cv.notify_all();
	}

  private:
	std::condition_variable cv; // Используется для синхронизации потоков
	std::mutex mutex; // Защищает доступ к очереди и флагу stopped
	std::queue<int> queue;
	bool stopped{false}; // Сигнализирует о завершении работы
};

void example()
{
	Queue queue;
	std::atomic<int> total{0};

	/*
	 Заполняем очередь числами от 0 до productsCount-1.
	 После заполнения вызывает stop().
	*/
	auto producer = std::thread([&]() {
		for (int i = 0; i < productsCount; ++i) {
			queue.push(i);
		}
		queue.stop();
	});

	/*
	 Создаём 10 потоков-потребителей.
	 Каждый поток извлекает значения из очереди пока pop() возвращает true.
	 Каждый поток добавляет значения к общей сумме.
	*/
	std::vector<std::thread> consumers;
	for (int i = 0; i < 10; ++i)
	{
		consumers.emplace_back(std::thread([&total, &queue]() {
			int value{0};

			while (queue.pop(value))
			{
				total += value;
			}
		}));
	}

	producer.join();
	for(auto& c : consumers)
	{
		c.join();
	}

	std::cout << total << '\n';
	std::cout << productsCount * (productsCount - 1) / 2 << '\n';
}
} // namespace cv

int main()
{
	cv::example();
}
