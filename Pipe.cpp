#include "Pipe.h"
Pipe::Pipe(int size) :m_size(size) {};
void Pipe::sendData(int i)
{
    while (true)
    {
        if (is_producer)
        {
            list_mutex.lock();
            vec.push_back(i);
            is_producer = !(m_size >= vec.size());
            list_mutex.unlock();
            return;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
    }
}
int Pipe::receiveData()
{
    while (true)
    {
        if (!is_producer)
        {
            list_mutex.lock();
            int res = vec.back();
            vec.pop_back();
            is_producer = (vec.size() == 0);
            list_mutex.unlock();
            return res;
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
    }
}