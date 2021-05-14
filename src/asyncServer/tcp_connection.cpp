#include <asio.hpp>
#include <memory>

class tcp_connection : public std::enable_shared_from_this<tcp_connection>
{
public:
    static std::shared_ptr<tcp_connection> create(asio::io_context& io_context)
    {
        return std::make_shared<tcp_connection>(io_context);
    }

    asio::ip::tcp::socket& socket()
    {
        return socket_;
    }
private:
    tcp_connection(asio::io_context& io) 
      : socket_(io) 
    {

    }

    asio::ip::tcp::socket socket_;
};