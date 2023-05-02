#include "MergeSort.h"


MergeSort::MergeSort(int streams) : numStreams(streams){}

void MergeSort::splitVector(std::vector<int> & vector)
{
    bool flag;
    int size = vector.size();
    if (size / 2 == 0)
    {
        return;
    }
    std::vector<int> v1;
    std::vector<int> v2;
    int count = 0;
    int m = size / 2;
    for (int i = 0; i < m; i++, count++)
    {
        int a = vector[count];
        v1.push_back(a);
    }
    for (int i = m; i < size; i++, count++)
    {
        int a = vector[count];
        v2.push_back(a);
    }
    int streams;
    counter.getCounter(streams);
    std::future<void> f1;
    std::future<void> f2;
    if (streams <= numStreams - 2)
    {
        f1 = std::async(std::launch::async, [&v1, this](){splitVector(v1);});
        f2 = std::async(std::launch::async, [&v2, this](){splitVector(v2);});
        counter.increase();
        flag = true;
    }
    else
    {
        f1 = std::async(std::launch::deferred, [&v1, this](){splitVector(v1);});
        f2 = std::async(std::launch::deferred, [&v2, this](){splitVector(v2);});
        flag = false;
    }
    f1.get();
    f2.get();
    if (flag == true)
    {
        counter.decrease();
    }
    merge(vector, v1, v2);
}

void MergeSort::merge(std::vector<int> & s_v, std::vector<int> & v1, std::vector<int> & v2)
{
    int s_count = 0, count_v1 = 0, count_v2 = 0;
    v1.push_back(1000);
    v2.push_back(1000);
    while (s_count != s_v.size())
    {
        if (v1[count_v1] > v2[count_v2])
        {
            s_v[s_count] = v2[count_v2];
            count_v2++;
        }
        else
        {
            s_v[s_count] = v1[count_v1];
            count_v1++;
        }
        s_count++;
    }
}