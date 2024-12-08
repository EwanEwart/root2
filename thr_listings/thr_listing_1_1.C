#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"Welcome to the Concurrent World\n";
}

void thr_listing_1_1()
{
    std::thread t(hello);
    t.join();
}
