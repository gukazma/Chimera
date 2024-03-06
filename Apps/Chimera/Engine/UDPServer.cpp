#include "UDPServer.h"
UDPServer::UDPServer(boost::asio::io_context& io_context, int port_, std::function<void(Engine)> fn_)
    : socket_(io_context, udp::endpoint(udp::v4(), port_))
    , _fn(fn_)
{
    start_receive();
}
void UDPServer::start_receive() {
    socket_.async_receive_from(boost::asio::buffer(&recv_buffer_, sizeof(recv_buffer_)),
                               remote_endpoint_,
                               std::bind(&UDPServer::handle_receive,
                                         this,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}

void UDPServer::handle_receive(const boost::system::error_code& error, std::size_t) {
    if (!error) {
        std::shared_ptr<std::string> message(new std::string("recived"));

        socket_.async_send_to(boost::asio::buffer(*message),
                              remote_endpoint_,
                              std::bind(&UDPServer::handle_send,
                                        this,
                                        message,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));

        std::cout << "Engien port: " << recv_buffer_.port << std::endl;
        std::cout << "Engien version: " << recv_buffer_.version << std::endl;

        start_receive();
    }
}
