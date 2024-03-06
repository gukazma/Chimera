#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
namespace Ui {
class MainWindow;
}

class Engine;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signal_acceptedEngine(std::shared_ptr<Engine> engine);

public slots:
    void slot_acceptedEngine(std::shared_ptr<Engine> engine);

private:
    void StartListenEngine();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
