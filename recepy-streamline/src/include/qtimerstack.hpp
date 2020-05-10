#ifndef QTIMERSTACK_HPP
#define QTIMERSTACK_HPP

#include "qmainwindow.h"
#include <QFont>
#include "qcookingtimer.hpp"

class QRecepy;

class QTimerStack
{
public:
    explicit QTimerStack(QMainWindow* parent);
    ~QTimerStack(){};

private:
    QMainWindow *parent_;
//    QRecepy * source_;

    std::vector<std::vector<QCookingTimer *>> timers_;
    std::vector<QWidget * > widgets_;

    QFont buttonF_;
    QFont timerF_;

public:
    void addTimer(int step, int time);
    void deployTimerWidget(int step);
    void initializeWidgets(int numSteps);
};

#endif // QTIMERSTACK_HPP
