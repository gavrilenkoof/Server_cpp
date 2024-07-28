#pragma once

#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>



using boost::asio::ip::udp;



namespace net
{


class udp_server
{
public:
    udp_server(boost::asio::io_context& io_context);
    ~udp_server();
private:

    void _start_receive();
    void _handle_receive(const boost::system::error_code& error, 
                            std::size_t bytes_transferred);

    void _handle_send(const boost::system::error_code& error,
                            std::size_t bytes_transferred);

private:
    udp::socket _socket;
    udp::endpoint _remote_endpoint;
    std::array<char, 1024> _recv_buffer;
};


}