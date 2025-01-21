#include "prog2.h"

int main(){
    asio::io_context ioContext;
    Prog2 start(ioContext, 2222);
    ioContext.run();
}