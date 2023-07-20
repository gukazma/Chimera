#define GLFW_INCLUDE_VULKAN
#include <Chimera/Vulkan/SurfaceData.h>
#include <GLFW/glfw3.h>
namespace Chimera {
namespace Vulkan {

SurfaceData::SurfaceData(vk::Instance const& instance, std::string const& windowName,
                         vk::Extent2D const& extent_)
    : m_extent(extent_)
    , m_window(WindowData::createWindow(windowName, extent_))
{
    VkSurfaceKHR _surface;
    VkResult     err = glfwCreateWindowSurface(
        static_cast<VkInstance>(instance), m_window.handle, nullptr, &_surface);
    if (err != VK_SUCCESS) throw std::runtime_error("Failed to create window!");
    m_surface = vk::SurfaceKHR(_surface);
}
}   // namespace Vulkan
}   // namespace Chimera