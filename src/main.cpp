#include <iostream>


#include <lib/server/server.h>



int main()
{

    auto server = net::Server(8888, "127.0.0.1");

    server.start();




    return 0;
}