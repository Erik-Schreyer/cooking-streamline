#include "qtimerstack.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <QGridLayout>
#include <fstream>
#include <sstream>

QTimerStack::QTimerStack(QMainWindow * parent) :
    parent_(parent),
    currentStep_(0)
//    source_(source)
{
    QFont buttonF( "Arial", 12);
    buttonF_=buttonF;
    QFont timerF( "Arial", 12);
    timerF_=timerF;
    QFont oneMinuteF( "Arial", 12, QFont::Bold);
    oneMinuteFont_=oneMinuteF;
}

void QTimerStack::addTimer(int step, int time){
    QCookingTimer * qTimer = new QCookingTimer(widgets_[step],time, buttonF_,timerF_,oneMinuteFont_);
    timers_[step].push_back(qTimer);
//    (qTimer->getLabel())->setGeometry(50,20*timers_[step].size(),100,20*(timers_[step].size()+1));

    dynamic_cast<QGridLayout*>(widgets_[step]->layout())->addWidget(qTimer->getButton(),timers_[step].size()+1,1);

    dynamic_cast<QGridLayout*>(widgets_[step]->layout())->addWidget(qTimer->getLabel(),timers_[step].size()+1,2);
}

void QTimerStack::initializeWidgets(int numSteps){
    QWidget * qWidget = nullptr;
    QGridLayout * layout= nullptr;
    QLabel * titleLabel = nullptr;
    for(int i=0; i< numSteps; i++){
        qWidget = new QWidget(parent_, Qt::Window);
        qWidget->setWindowTitle(QString::fromStdString("Timers for step"+std::to_string(i+1)));
        layout = new QGridLayout;
        qWidget->setLayout(layout);
        titleLabel = new QLabel(qWidget);
        titleLabel->setText(QString::fromStdString("Timers for Step "+std::to_string(i+1)+":"));
        layout->addWidget(titleLabel,1,1,1,2);
        widgets_.push_back(qWidget);
    }

}

void QTimerStack::initializeTimers(int numSteps){
    std::vector<QCookingTimer*> currentTimerVec;
    for(int i=0; i< numSteps; i++){
        timers_.push_back(currentTimerVec);
    }
}

void QTimerStack::deployTimerWidgetSlot(){
    widgets_[currentStep_]->show();
}
