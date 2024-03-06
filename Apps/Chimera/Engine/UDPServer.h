#pragma once

#include <array>
#include <boost/asio.hpp>
#include <ctime>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include "Engine.h"
using boost::asio::ip::udp;
class UDPServer
{
public:
    UDPServer(boost::asio::io_context& io_context, int port_, std::function<void(Engine)> fn_);
    ~UDPServer() = default;

private:
    void start_receive();

    void handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/);

    void handle_send(std::shared_ptr<std::string> /*message*/,
                     const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/)
    {}

    udp::socket         socket_;
    udp::endpoint       remote_endpoint_;
    Engine              recv_buffer_;
    std::function<void(Engine)> _fn;
};
