#pragma once
#include <atomic>
#include <mutex>
#include "Pipe.h"
#include <list>
#include <string>
#include <chrono>

class Pipe
{
    public:
        Pipe(int size);
        void sendData(int i);
        int receiveData();
    private:
        int m_size;
        std::atomic<bool> is_producer = true;
        std::list<int> vec;
        std::mutex list_mutex;
};