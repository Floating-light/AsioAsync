#include <asio.hpp>
#include <iostream>

#include "tcp_server.h"

int main()
{
    try
    {
        asio::io_context io_context;
        tcp_server server(io_context);

        // wait server to complete, but usually nerver.
        io_context.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}