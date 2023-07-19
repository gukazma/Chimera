#include <Chimera/Vulkan/Instance.h>
#include <GLFW/glfw3.h>
namespace Chimera {
namespace Vulkan {
std::vector<const char*> getRequiredExtensions()
{
    uint32_t     glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

#ifndef NDEBUG
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif   // !NDEBUG

    return extensions;
}
Instance::Instance()
{
    // initialize the vk::ApplicationInfo structure
    vk::ApplicationInfo applicationInfo("Chimera", 1, "Chimera", 1, VK_API_VERSION_1_1);
    auto                instanceExtensions = getRequiredExtensions();
    // initialize the vk::InstanceCreateInfo
    vk::InstanceCreateInfo instanceCreateInfo(
        {}, &applicationInfo, 0, {}, instanceExtensions.size(), instanceExtensions.data());

    // create an Instance
    m_nativeInstance = vk::createInstance(instanceCreateInfo);
}
}   // namespace Vulkan
}   // namespace Chimera
