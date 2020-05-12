#ifndef QCOOKINGTIMER_HPP
#define QCOOKINGTIMER_HPP

#include "qmainwindow.h"
#include "recepy.h"
#include <QObject>
#include <string>
#include <QMenuBar>
#include <QFont>
#include <QTimer>
#include <QLabel>
#include <QString>
#include <QPushButton>

class QCookingTimer : public QObject
{
public:
    explicit QCookingTimer(QWidget* parent, int time, QFont buttonF, QFont timerF,QFont oneMinuteF);
    ~QCookingTimer(){};

private:
    QWidget *parent_;
    unsigned int time_;
    unsigned int remainingTime_;

    QFont buttonF_;
    QFont timerF_;
    QFont oneMinuteFont_;
    QTimer * timer_;
    QLabel * timeLabel_;
    QPushButton * startResetButton_;

public slots:

    void startOrResetTimerSlot();
//    void resetTimerSlot();
    void secondUpdateSlot();


public:
    void oneMinuteWaring();

    QLabel * getLabel(){
        return timeLabel_;
    }

    void setLabelGeometry(int x,int y,int z, int w){
        timeLabel_->setGeometry(x,y,z,w);
    }

    void setLabelText(QString newText){
        timeLabel_->setText(newText);
    }

    QPushButton * getButton(){
        return startResetButton_;
    }

    void setButtonText(QString newText){
        startResetButton_->setText(newText);
    }
};

#endif // QCOOKINGTIMER_HPP
