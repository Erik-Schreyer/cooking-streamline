#ifndef QCOOKBOOK_HPP
#define QCOOKBOOK_HPP

#include "mainwindow.h"
#include <QObject>
#include <string>
#include <QMenuBar>

class CookingMenuBar;

class QCookbook : public QObject
{
public:
    explicit QCookbook(MainWindow* parent, CookingMenuBar * menuBar, std::string name, std::string location);
    ~QCookbook(){};

public slots:
    void newRecepySlot();
    void loadRecepySlot();
    void listRecepiesSlot();
    void removeRecepySlot();
    void closeCookbookSlot();

public:
    MainWindow * parent_;
    CookingMenuBar * menuBar_;
    QAction * thisMenuAction_;
    std::string name_;
    std::string location_;

};

#endif // QCOOKBOOK_HPP
