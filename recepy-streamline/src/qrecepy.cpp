#include "cookingmenubar.hpp"
#include "recepy.h"
#include "qrecepy.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <fstream>
#include <sstream>

QRecepy::QRecepy(QMainWindow * parent, CookingMenuBar * menuBar, std::string name, Recepy * recepy) :
    parent_(parent),
    menuBar_(menuBar),
    name_(name),
    recepy_(recepy),
    currentStep_(0)
{
    unsigned int numSteps= (recepy_->getSteps()).size();
    numSteps_=numSteps;

    QFont titleF( "Arial", 16, QFont::Bold);
    titleF_=titleF;
    QFont stepF( "Arial", 12);
    stepF_=stepF;
}

void QRecepy::nextStepSlot(){
//    parent_->layout()->removeWidget(widgets_[currentStep_]);
    if(currentStep_ < numSteps_-1){
        currentStep_++;
        qTimers_->incCurrentStep();
    //    parent_->layout()->addWidget(widgets_[currentStep_]);
        recepyWidget_->setCurrentIndex(currentStep_);
    }

}

void QRecepy::previousStepSlot(){
//    parent_->layout()->removeWidget(widgets_[currentStep_]);
    if(currentStep_ > 0){
        currentStep_--;
        qTimers_->decCurrentStep();
    //    parent_->layout()->addWidget(widgets_[currentStep_]);
    //    parent_->setCentralWidget(widgets_[currentStep_]);
        recepyWidget_->setCurrentIndex(currentStep_);
    }
}

//Show Ingredients Callback
void QRecepy::showIngredientsSlot(){
    QLabel *ingLabel = new QLabel(parent_,Qt::Window);
    ingLabel->setWindowTitle(QString::fromStdString(name_)+" Ingredients");
    ingLabel->setText(QString::fromStdString(recepy_->getIngredientString()));
    ingLabel->show();
}

void QRecepy::initializeProcess(){

    QStackedWidget * recepyWidget = new QStackedWidget;
    initializeTimerStack();
    unsigned int stepC=0;
    for(stepC=0;stepC<numSteps_;stepC++){
        setUpStepWidget(stepC);
        recepyWidget->addWidget(widgets_[stepC]);
    }
    recepyWidget_=recepyWidget;
    parent_->setCentralWidget(recepyWidget_);
//    parent_->layout()->addWidget(widgets_[0]);
//    widgets_[0]->show();
}

void QRecepy::setUpStepWidget(int step){
    QWidget* stepWidget = new QWidget(parent_);

    QLabel *nameLabel = new QLabel;
    nameLabel->setText(QString::fromStdString(recepy_->getName()));
    nameLabel->setFont(titleF_);
 //   nameLabel->setAlignment(Qt::AlignCenter);
 //   nameLabel->setGeometry(245,20,265,40);
 //   nameLabel->show();

    QLabel *stepLabel = new QLabel;
    stepLabel->setText(QString::fromStdString(recepy_->getStepAtStep(step)));
    stepLabel->setFont(stepF_);
    stepLabel->setWordWrap(true);
//    firstStepLabel->setGeometry(100,60,350,200);
//    firstStepLabel->show();

    QPushButton *timerButton = new QPushButton("&Show Timers", stepWidget);
    QPushButton *nextButton = new QPushButton("&Next Step", stepWidget);
    QPushButton *prevButton = new QPushButton("&Previous", stepWidget);

    connect(timerButton,&QPushButton::clicked,qTimers_,&QTimerStack::deployTimerWidgetSlot);
    connect(nextButton,&QPushButton::clicked,this,&QRecepy::nextStepSlot);
    connect(prevButton,&QPushButton::clicked,this,&QRecepy::previousStepSlot);

    QVBoxLayout * layout = new QVBoxLayout;
//    layout->setGeometry(QRect(0,0,100,200));
    layout->addWidget(nameLabel);
    layout->addWidget(stepLabel);
    layout->addWidget(timerButton);
    layout->addWidget(nextButton);
    layout->addWidget(prevButton);

    stepWidget->setLayout(layout);



    widgets_.push_back(stepWidget);
}

void QRecepy::initializeTimerStack(){

    QTimerStack * qTimers = new QTimerStack(parent_);
    qTimers_=qTimers;
    qTimers_->initializeWidgets(numSteps_);
    qTimers_->initializeTimers(numSteps_);
    unsigned int stepC,timerC;
    unsigned int numTimers;
    for(stepC=0;stepC<numSteps_;stepC++){
        numTimers = (recepy_->getTimersAtStep(stepC)).size();
        for(timerC=0;timerC<numTimers;timerC++){
            qTimers_->addTimer(stepC,(recepy_->getTimersAtStep(stepC))[timerC]);
        }
    }
}
