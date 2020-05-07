#ifndef COOKINGMENU_HPP
#define COOKINGMENU_HPP
#include <QMenuBar>
#include <QMenu>

class CookingMenu : public QMenu
{
public:
    CookingMenu();
    ~CookingMenu();

    void addCookingMenu(QMenuBar* menubar){
        menubar->addMenu("&Cooking");
    }


};

#endif // COOKINGMENU_HPP
