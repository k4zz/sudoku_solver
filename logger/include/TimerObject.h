#pragma once

#include "Logger.h"

#include <chrono>

class TimerObject
{
public:
    TimerObject() { start = std::chrono::steady_clock::now(); }
    ~TimerObject() {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end -start).count();
        Log("Duration: " + std::to_string(duration) + "[ms]");
    };
private:
    std::chrono::steady_clock::time_point start;
};