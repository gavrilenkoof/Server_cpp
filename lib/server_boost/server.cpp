
#include "server.h"




namespace net
{

udp_server::udp_server(boost::asio::io_context& io_context):
    _socket(io_context, udp::endpoint(udp::v4(), 8888))
{
    _start_receive();
}

udp_server::~udp_server()
{

}


void udp_server::_start_receive()
{

    _socket.async_receive_from(
        boost::asio::buffer(_recv_buffer), _remote_endpoint,
        boost::bind(&udp_server::_handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));

}


void udp_server::_handle_receive(const boost::system::error_code& error, 
                                    std::size_t bytes_transferred)
{

    if(!error){
        std::shared_ptr<std::string> message(new std::string("Hello\n"));

        _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint, 
            boost::bind(&udp_server::_handle_send, this, 
            boost::asio::placeholders::error, 
            boost::asio::placeholders::bytes_transferred));
    }

}


void udp_server::_handle_send(const boost::system::error_code& error,
                                std::size_t bytes_transferred)
{
    
}


}