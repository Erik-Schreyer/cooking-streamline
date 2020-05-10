#ifndef QTIMERSTACK_HPP
#define QTIMERSTACK_HPP

#include "qmainwindow.h"
#include <QFont>
#include "qcookingtimer.hpp"

class QRecepy;

class QTimerStack : public QObject
{
public:
    explicit QTimerStack(QMainWindow* parent);
    ~QTimerStack(){};

private:
    QMainWindow *parent_;
//    QRecepy * source_;

    std::vector<std::vector<QCookingTimer *>> timers_;
    std::vector<QWidget * > widgets_;

    int currentStep_;

    QFont buttonF_;
    QFont timerF_;

public slots:
    void deployTimerWidgetSlot();

public:
    void addTimer(int step, int time);
    void initializeWidgets(int numSteps);
    void initializeTimers(int numSteps);
    void incCurrentStep(){
        currentStep_++;
    }
    void decCurrentStep(){
        currentStep_--;
    }

};

#endif // QTIMERSTACK_HPP
