#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <iostream>

using boost::asio::ip::udp;

void sendBroadcast(boost::asio::io_context& io_context, udp::socket& socket,
                   udp::endpoint& broadcast_endpoint)
{
    std::string message = "ChimeraEngine";
    socket.send_to(boost::asio::buffer(message), broadcast_endpoint);

    // 设置定时器，每隔一段时间发送一次广播
    boost::asio::steady_timer timer(io_context, std::chrono::seconds(5));
    timer.async_wait([&](const boost::system::error_code& /*error*/) {
        sendBroadcast(io_context, socket, broadcast_endpoint);
    });
}

int main()
{
    try {
        boost::asio::io_context io_context;

        // 创建一个UDP socket
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));
        socket.set_option(udp::socket::broadcast(true));

        udp::endpoint broadcast_endpoint(boost::asio::ip::address_v4::broadcast(), 12345);

        // 初次发送广播消息
        sendBroadcast(io_context, socket, broadcast_endpoint);

        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}