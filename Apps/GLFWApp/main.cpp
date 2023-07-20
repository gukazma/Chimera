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
#include <Chimera/Vulkan/SurfaceData.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>
int main(int argc, char** argv)
{
    Chimera::Vulkan::Instance& instance = Chimera::Vulkan::Instance::getInstance();

    if (!instance.m_surfacedata->m_window.handle) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(instance.m_surfacedata->m_window.handle);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(instance.m_surfacedata->m_window.handle)) {
        /* Swap front and back buffers */
        glfwSwapBuffers(instance.m_surfacedata->m_window.handle);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}