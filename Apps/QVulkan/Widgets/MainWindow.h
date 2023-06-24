/*
 * @Author       : geekgary-x && geekgary-x@proton.me
 * @Date         : 2023-06-21 22:55:43
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\Widgets\MainWindow.h
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class VulkanWindow;
class QVulkanInstance;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow*  ui;
    VulkanWindow*    m_vulkanWindow;
    QVulkanInstance* m_vulkanInstance;
};

#endif   // MAINWINDOW_H
