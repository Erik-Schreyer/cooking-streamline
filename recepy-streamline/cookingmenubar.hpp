#ifndef COOKINGMENUBAR_HPP
#define COOKINGMENUBAR_HPP

#include "qcookbook.hpp"

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <vector>
#include <string>
class QAction;
class QMenu;

class CookingMenuBar : public QMainWindow
{
    Q_OBJECT

public:
    CookingMenuBar(QMainWindow *inMainWindow); // Constructor
    ~CookingMenuBar();                         // Destructor

private:
    QMainWindow  *mainWindow_;

private slots:
    // Declare function prototypes
    void openCookbookSlot();
    void openExtCookbookSlot();

private:
    // Declare function prototypes for creating actions and menus
    void createActions();
    void createCookbookActions();
    void createMenus();

    void addCookbookMenu(const char* name, QCookbook * openedBook);

    // Define menubar elements
    QMenu *cookingmenu_;

    // Define menubar and toolbar actions
    QAction *openCookbook_;
    QAction *openExtCookbook_;
    QAction *quit_;

    //Cookbook menu actions
    QAction *newRecepy_;
    QAction *loadRecepy_;
    QAction *listRecepies_;
};

#endif // COOKINGMENUBAR_HPP
