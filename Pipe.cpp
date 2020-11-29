#include "Pipe.h"
Pipe::Pipe(int size) :m_size(size) {};
void Pipe::sendData(int i)
{
    while (is_full) {};
    list_mutex.lock();
    storage.push(i);
    is_full = (m_size <= storage.size());
    is_empty = (0 == storage.size());
    list_mutex.unlock();
    return;
}
int Pipe::receiveData()
{
    int result;
    while (is_empty) {};
    list_mutex.lock();
    result = storage.front();
    storage.pop();
    is_full = (m_size <= storage.size());
    is_empty = (0 == storage.size());
    list_mutex.unlock();
    return result;
}