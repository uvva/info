#include <iostream>
#include <asio.hpp>

class Prog2{
private:
    asio::ip::tcp::acceptor acceptTCP;
    asio::io_context& ioContext;
    void startAccept();
    void startWork(std::shared_ptr<asio::ip::tcp::socket> socket);
public:
    Prog2(asio::io_context&, short int port);
};