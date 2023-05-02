#pragma once

#include <vector>
#include <iostream>
#include <future>
#include  "StreamCounter.h"

class MergeSort
{
private:
    int numStreams;
    StreamCounter counter;
public:
    MergeSort(int);
    ~MergeSort() = default;
    void splitVector(std::vector<int> &);
    void merge(std::vector<int> &, std::vector<int> &, std::vector<int> &);
};