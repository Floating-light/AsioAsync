#include <iostream>
#include <functional>
#include <asio.hpp>

void asyncCallback(const asio::error_code& e, asio::steady_timer* t, int* count)
{
    if(*count < 5)
    {
        // std::cout << "async count : " << *count << std::endl;
        std::cout << *count << std::endl;
        ++(*count);
        // expiry() the expiry time point
        t->expires_at(t->expiry() + asio::chrono::seconds(1));
        // asio::placeholders::error;
        t->async_wait(std::bind(asyncCallback, std::placeholders::_1,t, count));
    }
    std::cout << "async callback, error code : " << e.value() << std::endl;
}

// no explicit call to ask the io_context to stop
// must the timer expired , the io_context runt return .
int main()
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(1));

    // io_context::run() guarantee the callback only be called from threads that 
    // call io_context::run()
    int count = 0;
    t.async_wait(std::bind(asyncCallback, std::placeholders::_1, &t, &count));

    std::cout << "pre run " << std::endl;

    // will wait the async complete.
    io.run(); // if timer is not expired , will return until timer expired.
    std::cout << "post run " << std::endl;

}