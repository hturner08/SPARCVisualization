#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QDialog>

namespace Ui {
class Properties;
}

class Properties : public QDialog
{
    Q_OBJECT

public:
    explicit Properties(QWidget *parent = nullptr, QString file = "");
    ~Properties();
    QString fileName;

private:
    Ui::Properties *ui;
};

#endif // PROPERTIES_H
