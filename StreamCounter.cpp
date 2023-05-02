#include "StreamCounter.h"

StreamCounter::StreamCounter() : counter(0) {}

void StreamCounter::increase()
{
    m.lock();
    counter += 2;
    m.unlock();
}

void StreamCounter::decrease()
{
    m.lock();
    counter -= 2;
    m.unlock();
}

void StreamCounter::getCounter(int & a)
{
    m.lock();
    a = counter;
    m.unlock();
}