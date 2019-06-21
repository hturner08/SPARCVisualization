#include "properties.h"
#include "ui_properties.h"
#include <QtDebug>
Properties::Properties(QWidget *parent, QString file) :
    QDialog(parent),
    ui(new Ui::Properties)
{
    ui->setupUi(this);
    fileName = file;
    connect(ui->runButton,SIGNAL(clicked()), parent,SLOT(graph()));
    connect(ui->cancelButton,SIGNAL(clicked()), this,SLOT(close()));
}

Properties::~Properties()
{
    delete ui;
}
