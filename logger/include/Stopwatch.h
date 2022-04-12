#pragma once

#include "Logger.h"

#include <chrono>
#include <functional>

class Stopwatch
{
public:
    Stopwatch()
    { start = std::chrono::steady_clock::now(); }

    ~Stopwatch()
    {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        Log("Duration: " + std::to_string(duration) + "[ms]");
    };
private:
    std::chrono::steady_clock::time_point start;
};

class FunctionStopwatch
{
public:
    template<class Function, class ...Args>
    static auto duration(Function&& func, Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        std::invoke(std::forward<Function>(func), std::forward<Args>(args)...);
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
    }
};