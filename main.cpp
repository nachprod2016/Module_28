#include "MergeSort.h"
#include <cstdio>
#include <ctime>
#include <iostream>
#include <future>
#include <string>
#include <cstdio>
#include <chrono>

int main()
{
    srand(time(NULL));
    bool flag;
    while (true)
    {
        std::string buf;
        while (true)
        {
            std::cout << "1 - Сортировать массив" << std::endl;
            std::cout << "0 - Завершить программу" << std::endl;
            std::cin >> buf;
            if (buf == "1")
            {
                flag = true;
                break;
            }
            else if (buf == "0")
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
        std::cout << "Размер массива: ";
        std::cin >> buf;
        int size = atoi(&buf[0]);
        if (size == 0)
        {
            continue;
        }
        std::cout << "Максимальное количество потоков: ";
        std::cin >> buf;
        int streams = atoi(&buf[0]);
        if (streams == 0)
        {
            continue;
        }
        std::vector<int> v1;
        std::cout << "Исходный массив: ";
        for (int i = 0; i < size; i++)
        {
            int a = rand() % 89 + 10;
            std::cout << a << " ";
            v1.push_back(a); 
        }
        std::cout << std::endl;
        MergeSort m(streams);
        auto start = std::chrono::high_resolution_clock::now();
        m.splitVector(v1);
        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Массив после сортировки: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << v1[i] << " "; 
        }   
        std::cout << std::endl;
        std::chrono::duration<float> res = end - start;
        std::cout << "Время сортировки: " << res.count() << " секунд" << std::endl;
    }
    return 0;
}