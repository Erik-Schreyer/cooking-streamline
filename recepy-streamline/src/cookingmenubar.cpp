#include "cookingmenubar.hpp"
#include "cookbooklocationdialog.hpp"
#include "mainwindow.h"
#include "qcookbook.hpp"
#include "qrecepy.hpp"


#include <QDebug>
#include <vector>
#include <QInputDialog>
#include <QDir>
#include <fstream>
#include <sstream>

CookingMenuBar::CookingMenuBar(MainWindow *parent)
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

    QStringList bookList;
    std::string directoryPath=INSTALL_DIRECTORY;

    std::ifstream listFile(directoryPath+"/cookbooks/list.txt");

    std::stringstream buffer;
    buffer << listFile.rdbuf();

    std::string currentCookbook;
    QString currentCookbookQ;

        while(buffer >> currentCookbook){
        currentCookbookQ = QString::fromUtf8(currentCookbook.c_str());
        bookList.append(currentCookbookQ);
    }


    QInputDialog *dialog = new QInputDialog();
    bool accepted;
    QString cookBook = dialog->getItem(this, "Choose Cookbook", "Choose:", bookList, 0, false, &accepted);

    if (accepted && !cookBook.isEmpty()){

      QCookbook * openenedBook = new QCookbook(this,this, cookBook.toStdString(),directoryPath+"/cookbooks/"+cookBook.toStdString());

      QByteArray nameArray = cookBook.toLocal8Bit();
      const char *charName = nameArray.data();

      addCookbookMenu(charName, openenedBook);
    }

}

// open Externel Cookbook with QFileDialog
void CookingMenuBar::openExtCookbookSlot()
{
    createCookbookActions();

    bool ok;
    QStringList entries = CookbookLocationDialog::getStrings(this, &ok);


    if (ok && !entries.isEmpty()){

      QCookbook * openenedBook = new QCookbook(this,this,entries[0].toStdString(),entries[1].toStdString());

      QByteArray nameArray = entries[0].toLocal8Bit();
      const char *charName = nameArray.data();
      addCookbookMenu(charName, openenedBook);
    }
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
    this->newRecepy_ = new QAction("&New Recepy", this);
    this->loadRecepy_ = new QAction("&Load Recepy", this);
    this->removeRecepy_ = new QAction("&Remove Recepy", this);
    this->listRecepies_ = new QAction("&List Recepies", this);

}

// Function for creating recepy actions
void CookingMenuBar::createRecepyActions()
{
    this->nextStep_ = new QAction("&Next Step", this);
    this->previousStep_ = new QAction("&Previous Step", this);
    this->showRecepy_ = new QAction("&Show Recepy", this);
    this->showIngredients_ = new QAction("&Show Ingredients", this);
}


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
    cookbookMenu->addAction(removeRecepy_);

//    cookbookMenu->addAction(listRecepies_);

    connect(loadRecepy_, &QAction::triggered, openedBook, &QCookbook::loadRecepySlot);
    connect(newRecepy_, &QAction::triggered, openedBook, &QCookbook::newRecepySlot);
    connect(removeRecepy_, &QAction::triggered, openedBook, &QCookbook::removeRecepySlot);

}

void CookingMenuBar::addRecepyMenu(const char *name, QRecepy *openedRecepy){
    QMenu * recepyMenu;
    recepyMenu = mainWindow_->menuBar()->addMenu(tr(name));

    recepyMenu->addAction(nextStep_);
    recepyMenu->addAction(previousStep_);
    recepyMenu->addAction(showRecepy_);
    recepyMenu->addAction(showIngredients_);

    connect(nextStep_, &QAction::triggered, openedRecepy, &QRecepy::nextStepSlot);
    connect(previousStep_, &QAction::triggered, openedRecepy, &QRecepy::previousStepSlot);
    connect(showRecepy_, &QAction::triggered, openedRecepy, &QRecepy::showRecepySlot);
    connect(showIngredients_, &QAction::triggered, openedRecepy, &QRecepy::showIngredientsSlot);

}
