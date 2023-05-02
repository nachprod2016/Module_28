#pragma once

#include <mutex>

class StreamCounter
{
private:
    std::mutex m;
    int counter;
public:
    StreamCounter();
    ~StreamCounter() = default;
    void increase();
    void decrease();
    void getCounter(int &);
};