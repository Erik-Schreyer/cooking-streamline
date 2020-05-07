#ifndef COOKINGMENUBAR_HPP
#define COOKINGMENUBAR_HPP

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

private:
    // Declare function prototypes for creating actions and menus
    void createActions();
    void createMenus();

    void addNewMenu(std::vector<QAction> items, char* name);

    // Define menubar elements
    QMenu *cookingmenu_;

    // Define menubar and toolbar actions
    QAction *openCookbook_;
    QAction *quit_;
};

#endif // COOKINGMENUBAR_HPP
