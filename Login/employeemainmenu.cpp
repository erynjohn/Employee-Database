#include "employeemainmenu.h"
#include "ui_employeemainmenu.h"

EmployeeMainMenu::EmployeeMainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeMainMenu)
{
    ui->setupUi(this);
}

EmployeeMainMenu::~EmployeeMainMenu()
{
    delete ui;
}

void EmployeeMainMenu::on_pushButton_HR_clicked()
{
    // Open new window from object to HR home //
    hrmain = new hrMain(this);
    hrmain->show();
}
