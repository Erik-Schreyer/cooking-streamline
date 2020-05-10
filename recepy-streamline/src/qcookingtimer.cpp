#include "qcookingtimer.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <string>

QCookingTimer::QCookingTimer(QWidget * parent, int time, QFont buttonF, QFont timerF) :
    parent_(parent),
    time_(time),
    remainingTime_(time),
    buttonF_(buttonF),
    timerF_(timerF)
{
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(QCookingTimer::secondUpdate));
    timer_=timer;

    QLabel *timeLabel = new QLabel(parent_);
    timeLabel->setText(QString::fromStdString(std::to_string(time_/60))
                       + QString::fromStdString(std::to_string(time_%60)));
    timeLabel->setFont(timerF_);
    timeLabel_=timeLabel;
}

void QCookingTimer::startOrResetTimerSlot(){
    remainingTime_=time_;
    timer_->start(1000);
}

/*
void QCookingTimer::resetTimerSlot(){
    remainingTime_=time_;
    timer_->start(1000);
}
*/
void QCookingTimer::secondUpdateSlot(){
    remainingTime_--;

    timeLabel_->setText(QString::fromStdString(std::to_string(remainingTime_/60))
                       + QString::fromStdString(std::to_string(remainingTime_%60)));

    if(remainingTime_==60){
        oneMinuteWaring();
    }
    if(remainingTime_==0){
        timer_->stop();
        //PLay sound
    }
}

void QCookingTimer::oneMinuteWaring(){
    timeLabel_->setStyleSheet("{color: #700020}");
}

