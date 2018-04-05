#include "hrmain.h"
#include "ui_hrmain.h"
#include "employeemainmenu.h"
#include "tableeditor.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>


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

// SELECT [EmpID],[FName],[LName],[EmpAddress],[EmpJobTitle],[HireDate],[TerminationDate] FROM [GbManuf][dbo].[Employee]

void hrMain::on_pushButton_loadTable_clicked()
{
    LoginPage conn;
    conn.connOpen();

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Employee");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    qDebug() << (model->rowCount());


    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();


}


void hrMain::on_pushButton_clicked()
{
    // connect line edits with pushbutton to populate the database
}

//void hrMain::on_pushButton_add_clicked()
//{
//    QSqlQuery qry;
//    qry.exec("INSERT INTO [GbManuf].[dbo].[Employee][FName],[LName],[EmpAddress],[EmpJobTitle],[HireDate]) VALUES ('','','','','')");
//}

void hrMain::on_pushButton_edit_clicked()
{
//    LoginPage conn;
//    conn.connOpen();

//    QSqlQueryModel *model = new QSqlQueryModel();
//    QSqlQuery* qry = new QSqlQuery(conn.db);
//    qry->prepare("SELECT * FROM Employee");
//    qry->exec();
//    model->setQuery(*qry);
//    ui->tableView->setModel(model);
//    qDebug() << (model->rowCount());

//    this->hide();
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->resizeColumnsToContents();
//    view->show();
}

void hrMain::on_pushButton_save_clicked()
{

    QString Last, First, Address, job, Hire;
    Last=ui->lineEdit_LName->text();
    First=ui->lineEdit_FName->text();
    Address=ui->lineEdit_EmpAddress->text();
    job=ui->lineEdit_EmpJobTitle->text();
    Hire=ui->lineEdit_hire->text();

    QSqlQuery query;
    query.prepare( "INSERT INTO Employee (FName, LName, EmpAddress, EmpJobTitle, HireDate) VALUES (?, ?, ?, ?, ?)" );
    query.addBindValue(Last);
    query.addBindValue(First);
    query.addBindValue(Address);
    query.addBindValue(job);
    query.addBindValue(Hire);



    {
        if(query.exec())
        {
            QMessageBox::critical(this, "Save","Database updated!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Update Failed!");
        }
    }
}
