#include <Chimera/Vulkan/Device.h>
#include <Chimera/Vulkan/Instance.h>
#include <Chimera/Vulkan/SurfaceData.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>
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

uint32_t findGraphicsQueueFamilyIndex(
    std::vector<vk::QueueFamilyProperties> const& queueFamilyProperties)
{
    // get the first index into queueFamiliyProperties which supports graphics
    std::vector<vk::QueueFamilyProperties>::const_iterator graphicsQueueFamilyProperty =
        std::find_if(queueFamilyProperties.begin(),
                     queueFamilyProperties.end(),
                     [](vk::QueueFamilyProperties const& qfp) {
                         return qfp.queueFlags & vk::QueueFlagBits::eGraphics;
                     });
    assert(graphicsQueueFamilyProperty != queueFamilyProperties.end());
    return static_cast<uint32_t>(
        std::distance(queueFamilyProperties.begin(), graphicsQueueFamilyProperty));
}

std::pair<uint32_t, uint32_t> findGraphicsAndPresentQueueFamilyIndex(
    vk::PhysicalDevice physicalDevice, vk::SurfaceKHR const& surface)
{
    std::vector<vk::QueueFamilyProperties> queueFamilyProperties =
        physicalDevice.getQueueFamilyProperties();
    // assert(queueFamilyProperties.size() < std::numeric_limits<uint32_t>::max());

    uint32_t graphicsQueueFamilyIndex = findGraphicsQueueFamilyIndex(queueFamilyProperties);
    if (physicalDevice.getSurfaceSupportKHR(graphicsQueueFamilyIndex, surface)) {
        return std::make_pair(graphicsQueueFamilyIndex,
                              graphicsQueueFamilyIndex);   // the first graphicsQueueFamilyIndex
                                                           // does also support presents
    }

    // the graphicsQueueFamilyIndex doesn't support present -> look for an other family index that
    // supports both graphics and present
    for (size_t i = 0; i < queueFamilyProperties.size(); i++) {
        if ((queueFamilyProperties[i].queueFlags & vk::QueueFlagBits::eGraphics) &&
            physicalDevice.getSurfaceSupportKHR(static_cast<uint32_t>(i), surface)) {
            return std::make_pair(static_cast<uint32_t>(i), static_cast<uint32_t>(i));
        }
    }

    // there's nothing like a single family index that supports both graphics and present -> look
    // for an other family index that supports present
    for (size_t i = 0; i < queueFamilyProperties.size(); i++) {
        if (physicalDevice.getSurfaceSupportKHR(static_cast<uint32_t>(i), surface)) {
            return std::make_pair(graphicsQueueFamilyIndex, static_cast<uint32_t>(i));
        }
    }

    throw std::runtime_error("Could not find queues for both graphics or present -> terminating");
}

vk::Device createDevice(vk::PhysicalDevice const& physicalDevice, uint32_t queueFamilyIndex,
                        std::vector<std::string> const&   extensions             = {},
                        vk::PhysicalDeviceFeatures const* physicalDeviceFeatures = nullptr,
                        void const*                       pNext                  = nullptr)
{
    std::vector<char const*> enabledExtensions;
    enabledExtensions.reserve(extensions.size());
    for (auto const& ext : extensions) {
        enabledExtensions.push_back(ext.data());
    }

    float                     queuePriority = 0.0f;
    vk::DeviceQueueCreateInfo deviceQueueCreateInfo({}, queueFamilyIndex, 1, &queuePriority);
    vk::DeviceCreateInfo      deviceCreateInfo(
        {}, deviceQueueCreateInfo, {}, enabledExtensions, physicalDeviceFeatures, pNext);

    vk::Device device = physicalDevice.createDevice(deviceCreateInfo);
#if (VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1)
    // initialize function pointers for instance
    VULKAN_HPP_DEFAULT_DISPATCHER.init(device);
#endif
    return device;
}

std::vector<std::string> getDeviceExtensions()
{
    return {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
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
    m_surfacedata =
        std::make_shared<SurfaceData>(m_nativeInstance, "Chimera", vk::Extent2D(500, 500));
}
Instance& Instance::getInstance()
{
    static Instance s_instance;
    return s_instance;
}
vk::Device Instance::createGraphicNativeDevice()
{
    vk::PhysicalDevice physicalDevice = m_nativeInstance.enumeratePhysicalDevices().front();
    SurfaceData        surfacedata;
    std::pair<uint32_t, uint32_t> graphicsAndPresentQueueFamilyIndex =
        findGraphicsAndPresentQueueFamilyIndex(physicalDevice, m_surfacedata->m_surface);
    vk::Device device = createDevice(
        physicalDevice, graphicsAndPresentQueueFamilyIndex.first, getDeviceExtensions());
    return device;
}
std::shared_ptr<Device> Instance::createGraphicDevice()
{
    vk::Device              nativeDevice = createGraphicNativeDevice();
    std::shared_ptr<Device> device       = std::make_shared<Device>(nativeDevice);
    return device;
}
}   // namespace Vulkan
}   // namespace Chimera
