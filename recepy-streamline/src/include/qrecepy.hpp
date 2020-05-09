#ifndef QRECEPY_HPP
#define QRECEPY_HPP

#include "qmainwindow.h"
#include "recepy.h"
#include <QObject>
#include <string>
#include <QMenuBar>

class CookingMenuBar;

class QRecepy : public QObject
{
public:
    explicit QRecepy(QMainWindow* parent, CookingMenuBar * menuBar, std::string name, Recepy * recepy);
    ~QRecepy(){};

public slots:
    void nextStepSlot();
    void showIngredientsSlot();
    void previousStepSlot();
    void saveRecepySlot();

public:
    QWidget * parent_;
    CookingMenuBar * menuBar_;
    std::string name_;
    std::string location_;
    Recepy* recepy_;

    QFont titleF_;
    QFont stepF_;

    void initializeProcess();
};

#endif // QRECEPY_HPP
