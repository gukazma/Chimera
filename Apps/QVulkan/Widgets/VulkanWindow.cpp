#include "VulkanWindow.h"
/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-23 21:06:30
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\VulkanWindow.cpp
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
VulkanWindow::VulkanWindow(QWindow* parent)
    : QVulkanWindow(parent)
{}
QVulkanWindowRenderer* VulkanWindow::createRenderer()
{
    return new VulkanRenderer(this);
}
