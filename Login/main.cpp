#include "loginpage.h"
#include <QApplication>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();

    LoginPage conn;
    conn.connOpen();


    //Test qry the database
    QSqlQuery qry;

    if(qry.exec("SELECT * FROM [GbManuf].[dbo].[Employee]"))
    {
        while(qry.next())
        {
            qDebug() << qry.value(1).toString();
        }
    }
    else
    {
        qDebug() << "Database Closed!";
    }
    conn.connClose();

// Source string
//Server=localhost\SQLEXPRESS01;Database=master;Trusted_Connection=True;


return a.exec();
}
