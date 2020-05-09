#include "cookingmenubar.hpp"
#include "recepy.h"
#include "qrecepy.hpp"

#include <QInputDialog>
#include <QDir>
#include <QLabel>
#include <fstream>
#include <sstream>

QRecepy::QRecepy(QMainWindow * parent, CookingMenuBar * menuBar, std::string name, Recepy * recepy) :
    parent_(parent),
    menuBar_(menuBar),
    name_(name),
    recepy_(recepy)
{
    QFont titleF( "Arial", 16, QFont::Bold);
    titleF_=titleF;
    QFont stepF( "Arial", 12);
    stepF_=stepF;
}

void QRecepy::nextStepSlot(){}
void QRecepy::previousStepSlot(){}

//Show Ingredients Callback
void QRecepy::showIngredientsSlot(){
    QLabel *ingLabel = new QLabel(parent_,Qt::Window);
    ingLabel->setWindowTitle(QString::fromStdString(name_)+" Ingredients");
    ingLabel->setText(QString::fromStdString(recepy_->getIngredientString()));
    ingLabel->show();

}

void QRecepy::initializeProcess(){
    QLabel *nameLabel = new QLabel(parent_);
    nameLabel->setText(QString::fromStdString(recepy_->getName()));
    nameLabel->setFont(titleF_);
 //   nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setGeometry(245,20,265,40);
    nameLabel->show();

    QLabel *firstStepLabel = new QLabel(parent_);
    firstStepLabel->setText(QString::fromStdString(recepy_->getStepAtStep(0)));
    firstStepLabel->setFont(stepF_);
    firstStepLabel->setWordWrap(true);
    firstStepLabel->setGeometry(100,60,350,200);
    firstStepLabel->show();


}
