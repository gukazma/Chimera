#pragma once
#include <Chimera/Vulkan/WindowData.h>
#include <vulkan/vulkan.hpp>
namespace Chimera {
namespace Vulkan {
struct SurfaceData
{
    SurfaceData() {}
    SurfaceData(vk::Instance const& instance, std::string const& windowName,
                vk::Extent2D const& extent);

    vk::Extent2D   m_extent;
    WindowData     m_window;
    vk::SurfaceKHR m_surface;
};
}   // namespace Vulkan
}   // namespace Chimera