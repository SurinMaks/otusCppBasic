#ifndef TIMER_H
#define TIMER_H
#include <ctime>
#include <chrono>
class Timer
{
    public:
        Timer();
        void StartTimer();
        void StopTimer();
        unsigned int getTimeDifferent();

    private:
        std::chrono::time_point<std::chrono::system_clock> start_time;
        std::chrono::time_point<std::chrono::system_clock> stop_time;
        bool isRunning{false};
};

#endif // TIMER_H
