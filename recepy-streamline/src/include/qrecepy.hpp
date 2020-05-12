#ifndef QRECEPY_HPP
#define QRECEPY_HPP

#include "qmainwindow.h"
#include "recepy.h"
#include <QObject>
#include <string>
#include <QMenuBar>
#include <QStackedWidget>
#include "qtimerstack.hpp"
#include "mainwindow.h"

class CookingMenuBar;

class QRecepy : public QObject
{
public:
    explicit QRecepy(MainWindow* parent, CookingMenuBar * menuBar, std::string name, Recepy * recepy);
    ~QRecepy(){};

public slots:
    void nextStepSlot();
    void showIngredientsSlot();
    void previousStepSlot();
    void showRecepySlot();
    void saveRecepySlot();
    void closeRecepySlot();

public:
    MainWindow * parent_;
    CookingMenuBar * menuBar_;
    QAction * thisMenuAction_;
    std::string name_;
    std::string location_;
    Recepy* recepy_;

    std::vector<QWidget*> widgets_;
    QTimerStack * qTimers_;

    QStackedWidget * recepyWidget_;

    unsigned int numSteps_;
    unsigned int currentStep_;
    unsigned int stackIndex_;

    QFont titleF_;
    QFont stepF_;

    void initializeProcess();
    void setUpStepWidget(int step);
    void addWidgetToMain(int step);
    void removeWidgetFromMain(int step);
    void initializeTimerStack();
};

#endif // QRECEPY_HPP
