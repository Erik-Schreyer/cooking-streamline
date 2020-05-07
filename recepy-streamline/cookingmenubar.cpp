#include "cookingmenubar.hpp"
#include "mainwindow.h"

#include <QDebug>
#include <vector>

CookingMenuBar::CookingMenuBar(QMainWindow *parent)
{
    mainWindow_ = parent;

    createActions(); // Create all individual menu actions
    createMenus();   // Create main window menubar
}

CookingMenuBar::~CookingMenuBar()
{
    // The destructor should not be needed, as the menubar is part of the
    // main window and will be deleted when the main window is closed.
}

// Create individual menu action callbacks
void CookingMenuBar::openCookbookSlot()
{
    qDebug() << "Pressing File->New!";
}


// Function for creating all menu actions
void CookingMenuBar::createActions()
{
    quit_ = new QAction("&Quit", this);
    openCookbook_ = new QAction("&Open Cookbook", this);

}

void CookingMenuBar::createMenus()
{

//    QMenuBar * mainMenuBar = menuBar();
//    QMenu * cookingmenu;

    cookingmenu_ = mainWindow_->menuBar()->addMenu(tr("&Cooking"));
    cookingmenu_->addAction(openCookbook_);
    cookingmenu_->addAction(quit_);

    connect(openCookbook_, &QAction::triggered, this, &CookingMenuBar::openCookbookSlot);
    connect(quit_, &QAction::triggered, qApp, QApplication::quit);

}

void CookingMenuBar::addNewMenu(std::vector<QAction> items,char* name){
    QMenu * newMenu;
    newMenu = mainWindow_->menuBar()->addMenu(tr(name));


}
