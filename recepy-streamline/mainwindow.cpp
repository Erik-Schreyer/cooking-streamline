#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

  QAction *quit = new QAction("&Quit", this);
  QAction *newRecepy = new QAction("&New Recepy", this);
  QAction *openCookbook = new QAction("&Open Cookbook", this);

  QMenu *file;
  QMenuBar * mainMenuBar = menuBar();
  file = mainMenuBar->addMenu("&Cooking");
  file->addAction(newRecepy);
  file->addAction(openCookbook);
  file->addAction(quit);

//  connect(newRecepy, &QAction::triggered, qApp, QApplication::quit);
  connect(openCookbook, &QAction::triggered, qApp, QApplication::quit);
  connect(quit, &QAction::triggered, qApp, QApplication::quit);
}
