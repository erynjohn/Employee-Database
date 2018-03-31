#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include "employeemainmenu.h"
#include "hrmain.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase db;
    void connClose()
    {
        db.close();
//        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        //Set var
        db = QSqlDatabase::addDatabase("QODBC3");
        //Set connection string
        db.setDatabaseName("DRIVER={SQL Server};Server=localhost\\SQLEXPRESS01;Database=GbManuf;Trusted_Connection=True");
        //connecting to database
        db.open();
        if(!db.open())
        {
            qDebug() << "Not Connected!";
            return false;
        }
        else
        {
            qDebug() << "Connected!";
            return true;
        }
    }

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

private slots:
    void on_login_clicked();

private:
    Ui::LoginPage *ui;
    // object of class //

};

#endif // LOGINPAGE_H
