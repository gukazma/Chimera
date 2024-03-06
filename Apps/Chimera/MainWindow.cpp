#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Engine/Engine.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建一个QWidget用于放置图标
    QWidget* widget    = new QWidget();
    QLabel*  iconLabel = new QLabel();
    QPixmap  iconPixmap(":/Icons/icons8_sphere_16.png");   // 替换为您的图标路径
    iconLabel->setPixmap(iconPixmap);

    // 将图标添加到QWidget中
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->addWidget(iconLabel);
    layout->setAlignment(Qt::AlignRight);
    ui->statusbar->addWidget(widget);
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

void MainWindow::StartListenEngine() {
    
}

void MainWindow::slot_acceptedEngine(std::shared_ptr<Engine> engine)
{

}
