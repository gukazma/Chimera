#pragma once
#include <Chimera/Vulkan/SurfaceData.h>
#include <vulkan/vulkan.hpp>
namespace Chimera {
namespace Vulkan {
class Instance
{
public:
    Instance();

    vk::Device createDefaultDevice();

public:
    vk::Instance       m_nativeInstance;
    vk::PhysicalDevice m_physicalDevice;
    SurfaceData        m_surfacedata;
};
}   // namespace Vulkan
}   // namespace Chimera