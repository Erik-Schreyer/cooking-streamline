#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QStackedWidget * mainStackedWidget_;

public:
    QStackedWidget * getMainStackedWidget(){
        return mainStackedWidget_;
    }
//    Ui::MainWindow *ui;
};
