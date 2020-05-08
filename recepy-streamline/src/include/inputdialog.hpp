#ifndef INPUTDIALOG_HPP
#define INPUTDIALOG_HPP


#include <QDialog>

class QLineEdit;
class QLabel;

class CookbookLocationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CookbookLocationDialog(QWidget *parent = nullptr);

    static QStringList getStrings(QWidget *parent, bool *ok = nullptr);

private:
    QList<QLineEdit*> fields;
};

#endif // INPUTDIALOG_HPP
