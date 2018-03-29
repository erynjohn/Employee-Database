#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_login_clicked()
{
    QString username = ui->lineEdit_usrname->text();
    QString password = ui->lineEdit_password->text();
    // Displays login message //

    if(username == "test" && password == "test")
    {
        QMessageBox::information(this, "Login", "Accepted");
        // hide old window and show new window from object //
        hide();
        employeeMainMenu = new EmployeeMainMenu(this);
        employeeMainMenu->show();
    }
    // wrong password warning message //
    else{
        QMessageBox::warning(this, "Login", "Failed");
    }

}
