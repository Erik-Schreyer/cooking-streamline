#include "qcookbook.hpp"
#include "cookingmenubar.hpp"
#include "recepy.h"
#include "qrecepy.hpp"
#include "newrecepydialog.hpp"

#include <QInputDialog>
#include <QDir>
#include <QMenuBar>
#include <fstream>
#include <sstream>

QCookbook::QCookbook(MainWindow * parent, CookingMenuBar * menuBar, std::string name, std::string location) :
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
    QString recepyName = dialog->getItem(parent_, "Choose Recepy", "Choose:", recepyList, 0, false, &accepted);


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
    listFile.close();
}

void QCookbook::newRecepySlot(){

    bool ok;
    QStringList entries = NewRecepyDialog::getStrings(parent_, &ok);

    std::string installdir = INSTALL_DIRECTORY;
    if (ok && !entries.isEmpty()){

        std::ofstream recepyFile(installdir+"/cookbooks/"+name_+"/"+entries[0].toStdString()+".recepy");
        recepyFile << entries[0].toStdString() << '\n';
        recepyFile << entries[1].toStdString() << '\n';
        recepyFile << entries[2].toStdString() << '\n';
        recepyFile << "Steps:" << '\n';
        recepyFile << entries[3].toStdString();
        recepyFile.close();

        std::ofstream listFile(installdir+"/cookbooks/"+name_+"/"+"list.txt",
                                std::ios::app);
        listFile << entries[0].toStdString()<<'\n';
        listFile.close();

    }

}

void QCookbook::removeRecepySlot(){

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
    QString recepyName = dialog->getItem(parent_, "Remove Recepy", "Remove:", recepyList, 0, false, &accepted);


    listFile.close();

    if(accepted && !recepyName.isEmpty()){
        std::string recepyLoc=this->location_+"/"+recepyName.toStdString()+".recepy";
        std::remove(recepyLoc.c_str());

        std::stringstream outBuffer;
        std::ifstream listF(directoryPath+"/cookbooks/"+name_+"/list.txt");
        std::string line;

        while(std::getline(listF,line)){
            if(line.find(recepyName.toStdString())!=line.npos){
                continue;
            }
            outBuffer << line << '\n';
        }

        listF.close();
        std::ofstream listFileOut;
        listFileOut.open(directoryPath+"/cookbooks/"+name_+"/list.txt",
                          std::ofstream::out | std::ofstream::trunc);
        listFileOut << outBuffer.str();
        listFileOut.close();

    }

}

void QCookbook::closeCookbookSlot(){

    parent_->menuBar()->removeAction(thisMenuAction_);

}
