#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
#include <asio.hpp>

class Prog1{
private:
    const std::string host = "localhost";
    std::mutex m;
    asio::io_context& ioContext;
    asio::ip::tcp::socket socket;
    short int port;
    void startConect(const std::string&);
public:
    Prog1(asio::io_context&, short int port);

    void potok2(std::string);

    void potok1();

};