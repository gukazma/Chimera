/*
 * @Author       : gukazma && gukazma@proton.me
 * @Date         : 2023-06-24 20:40:17
 * @FilePath     : \Chimera\Apps\GLFWApp\main.cpp
 * @Description  :
 * MIT License
 *
 * Copyright (c) 2023 gukazma
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files, to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 */
#include <Chimera/Vulkan/Instance.h>
#include <Chimera/Vulkan/WindowData.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

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
int main(int argc, char** argv)
{
    Chimera::Vulkan::WindowData windowdata =
        Chimera::Vulkan::WindowData::createWindow("Chimera", {600, 400});
    Chimera::Vulkan::Instance instance;

    if (!windowdata.handle) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(windowdata.handle);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(windowdata.handle)) {
        /* Swap front and back buffers */
        glfwSwapBuffers(windowdata.handle);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}