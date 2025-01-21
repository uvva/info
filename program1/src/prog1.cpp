#include "prog1.h"
#include "function.h"

Prog1::Prog1(asio::io_context& ioContext, short int port) : ioContext(ioContext), socket(ioContext), port(port){}

void Prog1::potok2(std::string str){
    m.lock();
    std::cout << str << '\n';
    startConect(std::to_string(func::calculat(str)));
    m.unlock();
}

void Prog1::startConect(const std::string& str){
    try{
        asio::ip::tcp::resolver resolver(ioContext);
        auto endpoints = resolver.resolve(host, std::to_string(port));
        asio::connect(socket, endpoints);
        asio::async_write(socket, asio::buffer(str), [this](const asio::error_code& er, std::size_t){});
    }
    catch(const asio::system_error& er){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        startConect(str);
    }
}

void Prog1::potok1(){
    std::string stb = "";
    while(true){
        std::string str;
        std::cin >> str;

        if(str.size() > 64){
            std::cout << "Incorrect size string\n";
            continue;
        }
        int i = 0;
        for(auto x : str){
            if(isdigit(x)){
                i++;
            }
        }
        if(i != str.size()){
            std::cout << "Incorrect simbol string\n";
            continue;
        }
        func::sorted(str);
        stb += str;
        if(m.try_lock()){
            m.unlock();
            std::async(std::launch::async, &Prog1::potok2, this, str);
            str.clear();
        }
    }
}