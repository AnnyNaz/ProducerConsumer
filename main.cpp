
#include <iostream>
#include <thread>
#include <mutex>
#include "Pipe.h"
#include <list>
#include <string>
#include <chrono>
#include <assert.h>

using namespace std;


Pipe pipe(10);

void producer()
{
    for (int i = 0; i <= 100; ++i)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10));
        pipe.sendData(i);
        std::cout << "sended: " << i << std::endl;
    }
    std::cout << "producer_exit" << std::endl;
}

void consumer()
{
    int i = 0;
    while (i != 100)
    {
        i = pipe.receiveData();
        std::cout << "received: " << i << std::endl;
    }
    std::cout << "customer_exit" << std::endl;
}


int main()
{
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    system("pause");

}