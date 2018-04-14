#include "hrmain.h"
#include "ui_hrmain.h"
#include "employeemainmenu.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QDate>


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
    // hide old window and show new window //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}
// Refresh table view //
void hrMain::on_pushButton_loadTable_clicked()
{
    LoginPage conn;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Emp");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    qDebug() << (model->rowCount());

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();


}
// Update table information //
void hrMain::on_pushButton_edit_clicked()
{
    QString ID, Last, First, Address, job, hire;
    ID=ui->lineEdit_Badge->text();
    Last=ui->lineEdit_LName->text();
    First=ui->lineEdit_FName->text();
    Address=ui->lineEdit_EmpAddress->text();
    job=ui->lineEdit_EmpJobTitle->text();



    QSqlQuery query;
    query.prepare("UPDATE Emp SET FName='"+First+"', LName='"+Last+"', EmpAddress='"+Address+"', EmpID='"+ID+"', EmpJobTitle='"+job+"' WHERE EmpID='"+ID+"'");
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

// Save table information//
void hrMain::on_pushButton_save_clicked()
{
    QString Last, First, Address, job, badge;
    Last=ui->lineEdit_LName->text();
    First=ui->lineEdit_FName->text();
    Address=ui->lineEdit_EmpAddress->text();
    job=ui->lineEdit_EmpJobTitle->text();
    badge=ui->lineEdit_Badge->text();
    QDate date = QDate::currentDate();
    ui->dateEdit_hr->setDate(date);

    QSqlQuery query;

    query.prepare( "INSERT INTO Emp (FName, LName, EmpAddress, EmpJobTitle, EmpID, HireDate) VALUES (?, ?, ?, ?, ?, ?)" );
     query.addBindValue(Last);
    query.addBindValue(First);
    query.addBindValue(Address);
    query.addBindValue(job);
    query.addBindValue(date);
    query.addBindValue(badge);
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
// Delete table information //
void hrMain::on_pushButton_delete_clicked()
{
    QString badge;
    badge=ui->lineEdit_Badge->text();
    QSqlQuery query;
    query.prepare("DELETE FROM Emp WHERE EmpID='"+badge+"'");

    {
        if(query.exec())
        {

            QMessageBox::critical(this, "Delete","Database updated!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Delete Failed!");
        }
    }
}
