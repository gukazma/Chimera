#pragma once
#include <Chimera/Vulkan/Instance.h>
#include <vulkan/vulkan.hpp>
namespace Chimera {
namespace Vulkan {
class Device
{
public:
    Device() = default;
    Device(vk::Device& device_);

public:
    vk::Device m_nativeDevice;
};
}   // namespace Vulkan
}   // namespace Chimera