#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

int main()
{
    try {
        boost::asio::io_context io_context;

        udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));
        socket.set_option(udp::socket::broadcast(true));

        udp::endpoint broadcast_endpoint(boost::asio::ip::address_v4::broadcast(), 25557);

        std::string message = "Hello, this is a broadcast message!";
        socket.send_to(boost::asio::buffer(message), broadcast_endpoint);

        std::cout << "Message sent: " << message << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
