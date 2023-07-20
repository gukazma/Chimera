#pragma once
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

namespace Chimera {
namespace Vulkan {
struct WindowData
{
    static WindowData createWindow(std::string const& windowName, vk::Extent2D const& extent);
    WindowData() = default;
    WindowData(GLFWwindow* wnd, std::string const& name, vk::Extent2D const& extent);
    WindowData(const WindowData&) = delete;
    WindowData(WindowData&& other);
    ~WindowData() noexcept;

    GLFWwindow*  handle;
    std::string  name;
    vk::Extent2D extent;
};
}   // namespace Vulkan
}   // namespace Chimera
