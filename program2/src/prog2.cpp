#include "prog2.h"
#include "function.h"

Prog2::Prog2(asio::io_context& ioContext, short int port) : acceptTCP(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), ioContext(ioContext){
    startAccept();
}

void Prog2::startAccept(){
    std::shared_ptr<asio::ip::tcp::socket> socket = std::make_shared<asio::ip::tcp::socket>(ioContext);
    acceptTCP.async_accept(*socket,[this, socket](const asio::error_code& er){
        if(!er){
            startWork(socket);
        }
        startAccept();
    });
}

void Prog2::startWork(std::shared_ptr<asio::ip::tcp::socket> socket){
    std::shared_ptr<std::vector<char>> data = std::make_shared<std::vector<char>>(1024);
    socket->async_read_some(asio::buffer(*data), [this, socket, data](const asio::error_code& er, size_t byteTransf){
        if(!er){
            std::string mess(data->begin(), data->begin() + byteTransf);
            if(func::analys(mess)){
                std::cout << mess << '\n';
            }
            else{
                std::cout << "Error" << '\n';
            }
        }
    });
}