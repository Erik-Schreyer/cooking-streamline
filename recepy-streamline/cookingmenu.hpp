#ifndef COOKINGMENU_HPP
#define COOKINGMENU_HPP
#include <QMenuBar>
#include <QMenu>

class CookingMenu : public QMenu
{
protected:
    QMenuBar * parentMenu_;
public:
    CookingMenu(QWidget * parent,QMenuBar * parentMenu);
    ~CookingMenu(){}
public slots:
    void addCookingMenu();

//    void openCookbook();
};

#endif // COOKINGMENU_HPP
