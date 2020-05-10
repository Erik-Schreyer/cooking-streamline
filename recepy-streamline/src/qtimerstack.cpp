#include "qtimerstack.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <fstream>
#include <sstream>

QTimerStack::QTimerStack(QMainWindow * parent) :
    parent_(parent)
//    source_(source)
{
    QFont buttonF( "Arial", 16, QFont::Bold);
    buttonF_=buttonF;
    QFont timerF( "Arial", 12);
    timerF_=timerF;
}

void QTimerStack::addTimer(int step, int time){
    QCookingTimer * qTimer = new QCookingTimer(widgets_[step],time, buttonF_,timerF_);
    timers_[step].push_back(qTimer);
    (qTimer->getLabel())->setGeometry(50,20*timers_[step].size(),100,20*(timers_[step].size()+1));
//    (qTimer->getLabel())->show();
}

void QTimerStack::initializeWidgets(int numSteps){
    QWidget * qWidget = nullptr;
    for(int i=0; i< numSteps; i++){
        qWidget = new QWidget(parent_, Qt::Window);
        qWidget->setWindowTitle(QString::fromStdString("Timers for step"+std::to_string(i)+":"));
    }
}

void QTimerStack::deployTimerWidget(int step){
    widgets_[step]->show();
}
