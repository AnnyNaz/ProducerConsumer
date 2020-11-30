#include "Pipe.h"
#include <condition_variable>

Pipe::Pipe(int size) :m_size(size) {};
void Pipe::sendData(int i)
{
    std::unique_lock<std::mutex> lck(storage_mutex);
    producer.wait(lck, [&]() {return m_size >= storage.size(); });
    storage.push(i);
    consumer.notify_one();
    return;
}
int Pipe::receiveData()
{
    int result;
    std::unique_lock<std::mutex> lck(storage_mutex);
    consumer.wait(lck, [&]() {return 0 != storage.size(); });
    result = storage.front();
    storage.pop();
    producer.notify_one();
    return result;
}