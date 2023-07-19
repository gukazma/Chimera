#pragma once
#include <vulkan/vulkan.hpp>
namespace Chimera {
namespace Vulkan {
class Instance
{
public:
    Instance();

public:
    vk::Instance m_nativeInstance;
};
}   // namespace Vulkan
}   // namespace Chimera