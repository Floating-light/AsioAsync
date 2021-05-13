#include <iostream>
#include <asio.hpp>

int main()
{
    // IO execution context ---> IO functionlity
    asio::io_context io;

    std::cout << "Timer create" << std::endl;
    std::chrono::steady_clock::time_point Begin = std::chrono::high_resolution_clock::now();
    // provide IO functionality
    // set expire time 5s
    asio::steady_timer t(io, asio::chrono::seconds(5));

    // a timer must be "expired" or "not expired"
    // wait() will not return until the timer expired, (time after the timer create)
    // or return immediately if the timer is expired.
    t.wait();
    std::chrono::steady_clock::time_point End = std::chrono::high_resolution_clock::now();
    std::chrono::seconds dur = std::chrono::duration_cast<std::chrono::seconds>(End - Begin);
    std::cout << "Hello, asio steady_timer : " << dur.count() << std::endl;
}