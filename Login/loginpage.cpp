#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QString>


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
    ui->label->setText("");
    ui->label_2->setText("*");
    QString username = ui->lineEdit_usrname->text();
    QString password = ui->lineEdit_password->text();
    //Connect to the database
    connOpen();
    if(!db.isOpen())
    {
        qDebug() << "Database error";
    }
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM Employee WHERE LName=\'"+username +"'and EmpID='"+password +"'"))
    {
        if(qry.next())
        {
            //Set login authentication //

            QMessageBox::information(this, "Login", "You are now logged in");
            QString msg ="username = " + qry.value(0).toString() + " \n " +
                    "password = " + qry.value(3).toString();
            this->hide();
            EmployeeMainMenu empmenu;
            empmenu.setModal(true);
            empmenu.exec();

        }
        else
        {
            QMessageBox::warning(this, "Warning", "Login has failed");
        }
    }
}
