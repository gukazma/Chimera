/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-23 21:02:57
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\VulkanRenderer.h
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
#pragma once
#include <QVulkanWindow>

//! [0]
class VulkanRenderer : public QVulkanWindowRenderer
{
public:
    VulkanRenderer(QVulkanWindow* w);

    void initResources() override;
    void initSwapChainResources() override;
    void releaseSwapChainResources() override;
    void releaseResources() override;

    void startNextFrame() override;

private:
    QVulkanWindow*          m_window;
    QVulkanDeviceFunctions* m_devFuncs;
    float                   m_green = 0;
};