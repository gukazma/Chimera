/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-23 21:03:02
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\VulkanRenderer.cpp
 * @Description  :
 * MIT License
 *
 * Copyright (c) 2023 geekgary-x
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
#include "VulkanRenderer.h"
#include <QVulkanFunctions>

VulkanRenderer::VulkanRenderer(QVulkanWindow* w)
    : m_window(w)
{}

void VulkanRenderer::initResources()
{
    qDebug("initResources");

    m_devFuncs = m_window->vulkanInstance()->deviceFunctions(m_window->device());
}

void VulkanRenderer::initSwapChainResources()
{
    qDebug("initSwapChainResources");
}

void VulkanRenderer::releaseSwapChainResources()
{
    qDebug("releaseSwapChainResources");
}

void VulkanRenderer::releaseResources()
{
    qDebug("releaseResources");
}

void VulkanRenderer::startNextFrame()
{
    m_green += 0.005f;
    if (m_green > 1.0f) m_green = 0.0f;

    VkClearColorValue        clearColor = {{0.0f, m_green, 0.0f, 1.0f}};
    VkClearDepthStencilValue clearDS    = {1.0f, 0};
    VkClearValue             clearValues[2];
    memset(clearValues, 0, sizeof(clearValues));
    clearValues[0].color        = clearColor;
    clearValues[1].depthStencil = clearDS;

    VkRenderPassBeginInfo rpBeginInfo;
    memset(&rpBeginInfo, 0, sizeof(rpBeginInfo));
    rpBeginInfo.sType                    = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    rpBeginInfo.renderPass               = m_window->defaultRenderPass();
    rpBeginInfo.framebuffer              = m_window->currentFramebuffer();
    const QSize sz                       = m_window->swapChainImageSize();
    rpBeginInfo.renderArea.extent.width  = sz.width();
    rpBeginInfo.renderArea.extent.height = sz.height();
    rpBeginInfo.clearValueCount          = 2;
    rpBeginInfo.pClearValues             = clearValues;
    VkCommandBuffer cmdBuf               = m_window->currentCommandBuffer();
    m_devFuncs->vkCmdBeginRenderPass(cmdBuf, &rpBeginInfo, VK_SUBPASS_CONTENTS_INLINE);

    // Do nothing else. We will just clear to green, changing the component on
    // every invocation. This also helps verifying the rate to which the thread
    // is throttled to. (The elapsed time between startNextFrame calls should
    // typically be around 16 ms. Note that rendering is 2 frames ahead of what
    // is displayed.)

    m_devFuncs->vkCmdEndRenderPass(cmdBuf);

    m_window->frameReady();
    m_window->requestUpdate();   // render continuously, throttled by the presentation rate
}
