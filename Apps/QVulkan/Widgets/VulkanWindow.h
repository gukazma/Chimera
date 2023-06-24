/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-23 21:06:23
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\VulkanWindow.h
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
#include <QVulkanWindow>
class VulkanWindow : public QVulkanWindow
{
public:
    explicit VulkanWindow(QWindow* parent = nullptr);
    QVulkanWindowRenderer* createRenderer() override;
};