

#include "server.h"

namespace net
{

Server::Server(int port, std::string ipaddr):
    _port(port),
    _ipaddr(ipaddr),
    _socket_fd(-1),
    _sock_addr_len(sizeof(_socket_addr))
{
    
}


Server::~Server()
{
    if(_socket_fd == -1){
        close(-_socket_fd);
    }
}



int Server::init()
{
    int ret = -1;

    _socket_addr.sin_family = AF_INET;
    _socket_addr.sin_port = htons(_port);
    _socket_addr.sin_addr.s_addr = inet_addr(_ipaddr.c_str());

    _socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(_socket_fd == -1){
        std::cerr << "[ERROR] Error create socket\n";
        return ret;
    }


    int bind_status = bind(_socket_fd, (struct sockaddr*) &_socket_addr, sizeof(_socket_addr)); 
    if(bind_status < 0){
        std::cerr << "[ERROR] Error bind\n";
        return ret;
    }

    ret = 0;
    return ret;

}


void Server::recieve()
{
    _recv_size = recvfrom(_socket_fd, _buffer, BUFFER_SIZE, 0, (struct sockaddr*) & _socket_addr, (socklen_t*)_sock_addr_len);

}


void Server::start()
{

    init();


    for(;;){
        recieve();
    }


}



}