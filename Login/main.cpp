#include "loginpage.h"
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();

    //Set var
            QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");

            //Set connection string
            db.setDatabaseName("DRIVER={SQL Server};Server=localhost\\SQLEXPRESS01;Database=GbManuf;Trusted_Connection=True");
            //connecting to database
             db.open();
             if(db.open())
             {
                qDebug() << "Database Connected!";

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

                db.close();
             }
             else
             {
                 qDebug() << "Failed to connect = " << db.lastError().text();
             }
            // Source string
            //Server=localhost\SQLEXPRESS01;Database=master;Trusted_Connection=True;


        return a.exec();
    }
