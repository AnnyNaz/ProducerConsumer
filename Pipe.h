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
        std::condition_variable producer, consumer;
        std::queue<int> storage;
        std::mutex storage_mutex;
};