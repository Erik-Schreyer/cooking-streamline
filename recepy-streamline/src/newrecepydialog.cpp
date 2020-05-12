#include "newrecepydialog.hpp"

#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>

NewRecepyDialog::NewRecepyDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

    QLabel *nameLabel = new QLabel(QString("Recepy Name:"), this);
    QLineEdit *nameLine = new QLineEdit(this);
    lytMain->addRow(nameLabel, nameLine);

    lineFields_<< nameLine;

    QLabel *totalTimeLabel = new QLabel(QString("Total Time:"), this);
    QLineEdit *totalTimeLine = new QLineEdit(this);
    lytMain->addRow(totalTimeLabel, totalTimeLine);

    lineFields_ << totalTimeLine;

    QLabel *ingredientsLabel = new QLabel(QString("Ingredients:"), this);
    QTextEdit *ingredientsText = new QTextEdit(this);
    lytMain->addRow(ingredientsLabel, ingredientsText);

    textFields_ << ingredientsText;

    QLabel *stepsLabel = new QLabel(QString("Steps:"), this);
    QTextEdit *stepsText = new QTextEdit(this);
    lytMain->addRow(stepsLabel, stepsText);

    textFields_ << stepsText;

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Cancel,Qt::Horizontal, this );
    buttonBox->addButton("&Add to Cookbook",QDialogButtonBox::AcceptRole);
    lytMain->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &NewRecepyDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &NewRecepyDialog::reject);


    setLayout(lytMain);
}

QStringList NewRecepyDialog::getStrings(QWidget *parent, bool *ok)
{
    NewRecepyDialog *dialog = new NewRecepyDialog(parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto line, dialog->lineFields_) {
            list << line->text();
        }
        foreach (auto text, dialog->textFields_) {
            list << text->toPlainText();
        }
    }

    dialog->deleteLater();

    return list;
}
