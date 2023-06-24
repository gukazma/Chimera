/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-21 22:55:43
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\MainWindow.cpp
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
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "VulkanWindow.h"
#include <QVulkanInstance>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_vulkanInstance(new QVulkanInstance)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifndef Q_OS_ANDROID
    m_vulkanInstance->setLayers(QByteArrayList() << "VK_LAYER_LUNARG_standard_validation");
#else
    m_vulkanInstance->setLayers(QByteArrayList() << "VK_LAYER_GOOGLE_threading"
                                                 << "VK_LAYER_LUNARG_parameter_validation"
                                                 << "VK_LAYER_LUNARG_object_tracker"
                                                 << "VK_LAYER_LUNARG_core_validation"
                                                 << "VK_LAYER_LUNARG_image"
                                                 << "VK_LAYER_LUNARG_swapchain"
                                                 << "VK_LAYER_GOOGLE_unique_objects");
#endif

    if (!m_vulkanInstance->create())
        qFatal("Failed to create Vulkan instance: %d", m_vulkanInstance->errorCode());

    m_vulkanWindow = new VulkanWindow;
    m_vulkanWindow->setVulkanInstance(m_vulkanInstance);
    QWidget* vulkanWidget = QWidget::createWindowContainer(m_vulkanWindow, this);
    setCentralWidget(vulkanWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
