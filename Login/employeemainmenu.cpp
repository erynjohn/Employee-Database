#include "employeemainmenu.h"
#include "ui_employeemainmenu.h"
#include "loginpage.h"
#include "tableeditor.h"
#include <QMessageBox>


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
    // hide old window and show new window from object //

    this->hide();
    hrMain hrmain;
    hrmain.setModal(true);
    hrmain.exec();


}

void EmployeeMainMenu::on_pushButton_Tools_clicked()
{
    // hide old window and show new window from object //
    this->hide();
    tools Tools;
    Tools.setModal(true);
    Tools.exec();

}

void EmployeeMainMenu::on_pushButton_warehouse_clicked()
{
    // hide old window and show new window from object //
    this->hide();
    warehouse Warehouse;
    Warehouse.setModal(true);
    Warehouse.exec();

}

void EmployeeMainMenu::on_pushButton_logout_clicked()
{
    this->hide();
    LoginPage logout;
    logout.activateWindow();
    QMessageBox::information(this, "Thank You!", "You have been Logged Out");
    logout.close();
}
