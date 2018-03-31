#include "hrmain.h"
#include "ui_hrmain.h"
#include "employeemainmenu.h"

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

void hrMain::on_pushButton_Hback_clicked()
{
    // hide old window and show new window from object //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}
