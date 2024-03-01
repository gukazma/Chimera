#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton_imagePath, &QToolButton::clicked, [=](){
        auto result = QFileDialog::getExistingDirectoryUrl(this, "打开图片目录");
        if(!result.isEmpty())
        {
            ui->lineEdit_imagePath->setText(result.toString());
        }
    });

    connect(ui->toolButton_projectPath, &QToolButton::clicked, [=](){
        auto result = QFileDialog::getExistingDirectoryUrl(this, "打开工程目录");
        if(!result.isEmpty())
        {
            ui->lineEdit_projectPath->setText(result.toString());
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
