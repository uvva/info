#include "prog1.h"

int main(){
    asio::io_context ioContext;
    Prog1 start(ioContext, 2222);
    start.potok1();
    ioContext.run();
}