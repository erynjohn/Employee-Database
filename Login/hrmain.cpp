#include "hrmain.h"
#include "ui_hrmain.h"

hrMain::hrMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hrMain)
{
    ui->setupUi(this);
}

hrMain::~hrMain()
{
    delete ui;
}
