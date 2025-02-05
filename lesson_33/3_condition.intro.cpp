#include <atomic>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

const int productsCount = 1000;

namespace heater
{

class Queue
{
  public:
    void push(int value)
	{
        std::lock_guard lock{mutex};
        queue.push(value);
        has_data = true;
    }

    std::optional<int> pop()
	{
        std::optional<int> result;
        std::lock_guard lock{mutex};

        if (!queue.empty())
		{
            result = queue.front();
            queue.pop();
            has_data = !queue.empty();
        }
        return result;
    }

    bool hasData() const
	{
        return has_data;
    }

private:
    std::mutex mutex;
    std::queue<int> queue;
    std::atomic<bool> has_data{false};
};

void producer_function(Queue &queue)
{
    for (int i = 0; i < productsCount; ++i)
	{
        queue.push(i);
    }
}

void consumer_function(Queue &queue, int &total, std::atomic<bool> &stopped)
{
	/*
		queue.hasData() необходим для того, что обработать данные,
		 которые остались в очереди после завершения работы продюсера.
	*/
    while (!stopped || queue.hasData()) // HEATING!!!
	{
        if (auto value = queue.pop())
		{
            total += *value;
        }
		else if (!stopped)
		{
            // Короткая пауза только если producer еще работает
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    }
}

void example()
{
    Queue queue;
    std::atomic<bool> stopped{false};
    int total{0};

    auto producer = std::thread(producer_function, std::ref(queue));
    auto consumer = std::thread(consumer_function, std::ref(queue), std::ref(total), std::ref(stopped));

    producer.join();
    stopped = true;
    consumer.join();

    std::cout << "Actual sum: " << total << '\n';
    std::cout << "Expected sum: " << productsCount * (productsCount - 1) / 2 << '\n';
}

} // namespace heater

int main()
{
    heater::example();
}
