#include <Chimera/Vulkan/WindowData.h>
#include <iostream>

namespace Chimera {
namespace Vulkan {
WindowData::WindowData(GLFWwindow* wnd, std::string const& name, vk::Extent2D const& extent)
    : handle{wnd}
    , name{name}
    , extent{extent}
{}

WindowData::WindowData(WindowData&& other)
    : handle{}
    , name{}
    , extent{}
{
    std::swap(handle, other.handle);
    std::swap(name, other.name);
    std::swap(extent, other.extent);
}

WindowData::~WindowData() noexcept
{
    glfwDestroyWindow(handle);
}

WindowData WindowData::createWindow(std::string const& windowName, vk::Extent2D const& extent)
{
    struct glfwContext
    {
        glfwContext()
        {
            glfwInit();
            glfwSetErrorCallback([](int error, const char* msg) {
                std::cerr << "glfw: "
                          << "(" << error << ") " << msg << std::endl;
            });
        }

        ~glfwContext() { glfwTerminate(); }
    };

    static auto glfwCtx = glfwContext();
    (void)glfwCtx;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window =
        glfwCreateWindow(extent.width, extent.height, windowName.c_str(), nullptr, nullptr);
    return WindowData(window, windowName, extent);
}
}   // namespace Vulkan
}   // namespace Chimera
