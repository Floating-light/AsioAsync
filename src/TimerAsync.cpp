#include <iostream>
#include <asio.hpp>

void asyncCallback(const asio::error_code& e)
{
    std::cout << "async callback, error code : " << e.value() << std::endl;
}

int main()
{
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));

    // io_context::run() guarantee the callback only be called from threads that 
    // call io_context::run()
    t.async_wait(&asyncCallback);

    std::cout << "pre run " << std::endl;

    // will wait the async complete.
    // That is : return when no work to do : timer wait and callback
    io.run(); // if timer is not expired , will return until timer expired.
    std::cout << "post run " << std::endl;

}