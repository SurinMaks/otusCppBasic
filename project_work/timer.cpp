#include "timer.h"

Timer::Timer() {}

void Timer::StartTimer(){
    if (!isRunning) {
        start_time = std::chrono::system_clock::now();
        isRunning = true;
    }
}

void Timer::StopTimer(){
    if(isRunning){
        stop_time = std::chrono::system_clock::now();
        isRunning = false;
    }

}

unsigned int Timer::getTimeDifferent(){
    const unsigned int minites = 60;
    if (!isRunning) {
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop_time - start_time);
        int diffMinutes = duration.count();
        return diffMinutes;
    }
    return 0;
}
