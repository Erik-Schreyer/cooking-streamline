#include "qcookbook.hpp"
#include "cookingmenubar.hpp"
#include "recepy.h"
#include "qrecepy.hpp"

#include <QInputDialog>
#include <QDir>
#include <fstream>
#include <sstream>

QCookbook::QCookbook(QWidget * parent, CookingMenuBar * menuBar, std::string name, std::string location) :
    parent_(parent),
    menuBar_(menuBar),
    name_(name),
    location_(location)
{
}

void QCookbook::loadRecepySlot(){

    QStringList recepyList;
    std::string directoryPath=INSTALL_DIRECTORY;

    std::ifstream listFile(directoryPath+"/cookbooks/"+name_+"/list.txt");

    std::stringstream buffer;
    buffer << listFile.rdbuf();

    std::string currentRecepy;
    QString currentRecepyQ;

    while(std::getline(buffer, currentRecepy)){
        currentRecepyQ = QString::fromUtf8(currentRecepy.c_str());
        recepyList.append(currentRecepyQ);
    }


    QInputDialog *dialog = new QInputDialog();
    bool accepted;
    QString recepyName = dialog->getItem(parent_, "Choose Cookbook", "Choose:", recepyList, 0, false, &accepted);


    if(accepted && !recepyName.isEmpty()){
        Recepy * loadedRecepy = new Recepy(this->location_+"/"+recepyName.toStdString()+".recepy");
        QRecepy * qLoadedRecepy = new QRecepy(menuBar_->mainWindow_,menuBar_,
                                             recepyName.toStdString(), loadedRecepy);
        menuBar_->createRecepyActions();

        QByteArray nameArray = recepyName.toLocal8Bit();
        const char *charName = nameArray.data();

        menuBar_->addRecepyMenu(charName, qLoadedRecepy);
        qLoadedRecepy->initializeProcess();
    }

}
