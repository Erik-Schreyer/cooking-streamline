#include "qcookingtimer.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <QtMultimedia/QSound>
#include <string>

QCookingTimer::QCookingTimer(QWidget * parent, int time, QFont buttonF, QFont timerF, QFont oneMinuteF) :
    parent_(parent),
    time_(time),
    remainingTime_(time),
    buttonF_(buttonF),
    timerF_(timerF),
    oneMinuteFont_(oneMinuteF)
{
    QTimer * timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QCookingTimer::secondUpdateSlot);
    timer_=timer;

    QLabel *timeLabel = new QLabel(parent_);
    int hours = remainingTime_/3600;
    int minutes = (remainingTime_%3600)/60;
    int seconds = remainingTime_%60;
    char hoursStr[3];
    char minutesStr[3];
    char secondsStr[3];
    std::sprintf(hoursStr,"%02d",hours);
    std::sprintf(minutesStr,"%02d",minutes);
    std::sprintf(secondsStr,"%02d",seconds);

    timeLabel->setText(QString::fromStdString(hoursStr)+":"
                       + QString::fromStdString(minutesStr)+":"
                       + QString::fromStdString(secondsStr)+" h");

//    timeLabel->setText(QString::fromStdString(std::to_string(time_/60))+":"
//                       + QString::fromStdString(std::to_string(time_%60))+"min");
    timeLabel->setFont(timerF_);
    timeLabel_=timeLabel;

    QPushButton * startResetButton = new QPushButton("&Start:",parent_);
    startResetButton->setFont(buttonF_);
    connect(startResetButton,&QPushButton::clicked,this,&QCookingTimer::startOrResetTimerSlot);
    startResetButton_=startResetButton;
}

void QCookingTimer::startOrResetTimerSlot(){
    remainingTime_=time_;
    timer_->start(1000);
    startResetButton_->setText("&Reset:");
}

/*
void QCookingTimer::resetTimerSlot(){
    remainingTime_=time_;
    timer_->start(1000);
}
*/
void QCookingTimer::secondUpdateSlot(){
    remainingTime_--;
    int hours = remainingTime_/3600;
    int minutes = (remainingTime_%3600)/60;
    int seconds = remainingTime_%60;
    char hoursStr[3];
    char minutesStr[3];
    char secondsStr[3];
    std::sprintf(hoursStr,"%02d",hours);
    std::sprintf(minutesStr,"%02d",minutes);
    std::sprintf(secondsStr,"%02d",seconds);

    timeLabel_->setText(QString::fromStdString(hoursStr)+":"
                       + QString::fromStdString(minutesStr)+":"
                       + QString::fromStdString(secondsStr)+" h");

    timeLabel_->update();
    if(remainingTime_==60){
        oneMinuteWaring();
    }
    std::string installLoc = INSTALL_DIRECTORY;
    if(remainingTime_==0){
        timer_->stop();
        QSound::play(QString::fromStdString(installLoc+"/sounds/foghorn.wav"));
    }
}

void QCookingTimer::oneMinuteWaring(){
    timeLabel_->setFont(oneMinuteFont_);
    timeLabel_->update();
}

