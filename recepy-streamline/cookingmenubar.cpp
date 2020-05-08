#include "cookingmenubar.hpp"
#include "cookbooklocationdialog.hpp"
#include "mainwindow.h"
#include "qcookbook.hpp"

#include <QDebug>
#include <vector>
#include <QInputDialog>
#include <QDir>

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
//Open internal cookbook with list menu
void CookingMenuBar::openCookbookSlot()
{
    createCookbookActions();

  /*
    bool ok;
    QString cookBook = QInputDialog::getText(this, tr("Choose Cookbook"),
                                         tr("Enter cookbook directory:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
  */

    bool ok;
    QStringList entries = CookbookLocationDialog::getStrings(this, &ok);
    if (ok) {
        // use list
    }

    QCookbook * openenedBook = new QCookbook(this,entries[0].toStdString(),entries[1].toStdString());

    if (ok && !entries.isEmpty()){

      QByteArray nameArray = entries[0].toLocal8Bit();
      const char *charName = nameArray.data();
      addCookbookMenu(charName, openenedBook);
    }

}

// open Externel Cookbook with QFileDialog
void CookingMenuBar::openExtCookbookSlot()
{

}


// Function for creating all menu actions
void CookingMenuBar::createActions()
{
    this->quit_ = new QAction("&Quit", this);
    this->openCookbook_ = new QAction("&Open Cookbook", this);
    this->openExtCookbook_ = new QAction("&Open External Cookbook", this);
}

// Function for creating cookbook actions
void CookingMenuBar::createCookbookActions()
{
    this->newRecepy_ = new QAction("&New Recpy", this);
    this->loadRecepy_ = new QAction("&Load Recepy", this);
    this->listRecepies_ = new QAction("&List Recepies", this);

}

QAction *newRecepy_;
QAction *loadRecepy_;
QAction *listRecepies;


//Create menu in menubar
void CookingMenuBar::createMenus()
{

//    QMenuBar * mainMenuBar = menuBar();
//    QMenu * cookingmenu;

    cookingmenu_ = mainWindow_->menuBar()->addMenu(tr("&Cooking"));
    cookingmenu_->addAction(openCookbook_);
    cookingmenu_->addAction(openExtCookbook_);
    cookingmenu_->addAction(quit_);

    connect(openCookbook_, &QAction::triggered, this, &CookingMenuBar::openCookbookSlot);
    connect(openExtCookbook_, &QAction::triggered, this, &CookingMenuBar::openExtCookbookSlot);
    connect(quit_, &QAction::triggered, qApp, QApplication::quit);

}

void CookingMenuBar::addCookbookMenu(const char* name, QCookbook * openedBook){
    QMenu * cookbookMenu;
    cookbookMenu = mainWindow_->menuBar()->addMenu(tr(name));

    cookbookMenu->addAction(newRecepy_);
    cookbookMenu->addAction(loadRecepy_);
    cookbookMenu->addAction(listRecepies_);

    connect(loadRecepy_, &QAction::triggered, openedBook, &QCookbook::loadRecepySlot);

}
