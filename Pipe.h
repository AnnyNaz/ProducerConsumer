#pragma once
#include <atomic>
#include <mutex>
#include "Pipe.h"
#include <queue>
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
        std::atomic<bool> is_empty = true;
        std::atomic<bool> is_full = false;
        std::queue<int> storage;
        std::mutex list_mutex;

};