#ifndef QCOOKBOOK_HPP
#define QCOOKBOOK_HPP

#include <QObject>
#include <string>

class QCookbook : public QObject
{
public:
    explicit QCookbook(QWidget * parent, std::string name, std::string location);
    ~QCookbook(){};

public slots:
    void newRecepySlot();
    void loadRecepySlot();
    void listRecepiesSlot();

public:
    QWidget * parent_;
    std::string name_;
    std::string location_;

};

#endif // QCOOKBOOK_HPP
