#ifndef NEWRECEPYDIALOG_HPP
#define NEWRECEPYDIALOG_HPP

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>

class QLineEdit;
class QLabel;

class NewRecepyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewRecepyDialog(QWidget *parent = nullptr);

    static QStringList getStrings(QWidget *parent, bool *ok = nullptr);

private:
    QList<QLineEdit*> lineFields_;
    QList<QTextEdit*> textFields_;
};

#endif // NEWRECEPYDIALOG_HPP
