#pragma once
#include <memory>
#include <vulkan/vulkan.hpp>
namespace Chimera {
namespace Vulkan {
class SurfaceData;
class Device;
class Instance
{
public:
    static Instance&        getInstance();
    vk::Device              createGraphicNativeDevice();
    std::shared_ptr<Device> createGraphicDevice();

public:
    Instance();
    Instance(const Instance&)                                     = delete;
    Instance&                    operator=(const Instance& other) = delete;
    vk::Instance                 m_nativeInstance;
    vk::PhysicalDevice           m_physicalDevice;
    std::shared_ptr<SurfaceData> m_surfacedata;
};
}   // namespace Vulkan
}   // namespace Chimera