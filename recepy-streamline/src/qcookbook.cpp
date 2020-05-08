#include "qcookbook.hpp"
#include "recepy.h"

#include <QInputDialog>
#include <QDir>

QCookbook::QCookbook(QWidget * parent, std::string name, std::string location) :
    parent_(parent),
    name_(name),
    location_(location)
{
}

void QCookbook::loadRecepySlot(){
    bool ok;
    QString recepyName = QInputDialog::getText(this->parent_, tr("Choose Recepy"),
                                         tr("Recepy Name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);

    if(ok && !recepyName.isEmpty()){
        Recepy * loadedRecepy = new Recepy(this->location_+recepyName.toStdString());

    }
}
