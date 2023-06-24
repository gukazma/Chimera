/*
 * @Author       : geekgary-x 18017158729@163.com
 * @Date         : 2023-06-21 22:35:52
 * @LastEditors  : geekgary-x 18017158729@163.com
 * @LastEditTime : 2023-06-23 21:31:50
 * @FilePath     : \QVulkan-begin\Apps\QVulkan\main.cpp
 * @Description  :
 * Copyright (c) 2023 by geekgary-x email: 18017158729@163.com, All Rights Reserved.
 */
#include "Widgets/MainWindow.h"
#include <QApplication>
#include <QVulkanInstance>
#include <QVulkanWindowRenderer>
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow   mainwindow;
    mainwindow.show();



    return app.exec();
}