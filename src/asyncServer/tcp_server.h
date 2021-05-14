#include <asio.hpp>

class tcp_server
{
public:
    tcp_server(asio::io_context& io)
      : io_context_(io)
      , acceptor_(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 13))
    {
        start_accept();
    }
private:
    void start_accept()
    {
    }

    asio::io_context& io_context_;
    asio::ip::tcp::acceptor acceptor_; 
};