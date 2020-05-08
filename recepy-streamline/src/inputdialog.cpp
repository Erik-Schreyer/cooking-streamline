#include "inputdialog.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

CookbookLocationDialog::CookbookLocationDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

    for (int i = 0; i < 4; ++i)
    {
        QLabel *tLabel = new QLabel(QString("Text_%1:").arg(i), this);
        QLineEdit *tLine = new QLineEdit(this);
        lytMain->addRow(tLabel, tLine);

        fields << tLine;
    }

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &CookbookLocationDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &CookbookLocationDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList CookbookLocationDialog::getStrings(QWidget *parent, bool *ok)
{
    CookbookLocationDialog *dialog = new CookbookLocationDialog(parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}
