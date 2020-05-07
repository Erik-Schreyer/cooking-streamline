#include "cookingmenu.hpp"
#include "mainwindow.h"

CookingMenu::CookingMenu(QWidget* parent, QMenuBar * parentMenu) : parentMenu_(parentMenu)
{

    QAction *openCookbook = new QAction("&Open Cookbook", this);

    QMenu *cookingmenu;
    cookingmenu = new QMenu(parent);
    cookingmenu->addAction(openCookbook);


    connect(openCookbook, &QAction::triggered, qApp, QApplication::quit);
    QObject::connect(openCookbook, &QAction::triggered, this, &CookingMenu::addCookingMenu);

}

void CookingMenu::addCookingMenu(){

    (this->parentMenu_)->addMenu(this);
}
