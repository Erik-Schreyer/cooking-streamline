//#include "cookingmenu.hpp"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cookingmenubar.hpp"


#include <QWidget>
#include <QDebug>
#include <string>

//#include <QMenu>
//#include <QMenuBar>
#include <QGridLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::MainWindow)
{
    // Now populate empty menubar & toolbar
//    MWmenu->show();  // Shows a detached menubar (i.e. outside of the main window).


 //   ui->setupUi(this);

    CookingMenuBar *Cmenu = new CookingMenuBar(this);

    QStackedWidget * centralStackedWidget = new QStackedWidget(this);
    this->setCentralWidget(centralStackedWidget);
    mainStackedWidget_=centralStackedWidget;
//    QVBoxLayout* layout = new QVBoxLayout;
//    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
  //  delete ui;
}

/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

  QAction *quit = new QAction("&Quit", this);
  QAction *openCookbook = new QAction("&Open Cookbook", this);

  QMenuBar * mainMenuBar = menuBar();
  QMenu * cookingmenu;
  cookingmenu = mainMenuBar->addMenu("&Cooking");
  cookingmenu->addAction(openCookbook);
  cookingmenu->addAction(quit);

//  connect(openCookbook, &QAction::triggered, this, &M);
  connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

*/

