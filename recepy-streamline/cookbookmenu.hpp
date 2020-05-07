#ifndef COOKINGBOOKMENU_HPP
#define COOKINGBOOKMENU_HPP
#include <QMenuBar>
#include <QMenu>
#include <QMainWindow>

class CookBookMenu : public QMainWindow
{
Q_OBJECT
protected:
    QMenuBar * parentMenu_;
public:
    CookBookMenu(QWidget * parent,QMenuBar * parentMenu);
    ~CookBookMenu(){}

};

#endif // COOKBOOKMENU_HPP
