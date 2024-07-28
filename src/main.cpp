#include <iostream>


#include <lib/server/server.h>
#include <lib/server_boost/server.h>


int main()
{

    // auto server = net::Server(8888, "127.0.0.1");
    // server.start();

    try
    {
        boost::asio::io_context io_context;
        net::udp_server server(io_context);
        io_context.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}