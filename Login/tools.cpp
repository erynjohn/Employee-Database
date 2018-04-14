#include "tools.h"
#include "ui_tools.h"
#include "employeemainmenu.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>

tools::tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tools)
{
    ui->setupUi(this);
}

tools::~tools()
{
    delete ui;
}

void tools::on_pushButton_save_tool_clicked()
{
    //Save info into tool database//
    QString last, tool, date, badge;
    last=ui->lineEdi_LName->text();
    tool=ui->lineEdit_toolName->text();
    date=ui->lineEdit_checkout->text();
    badge=ui->lineEdit_badge_tools->text();

    QSqlQuery query;
    query.prepare( "INSERT INTO Tool (LastName, ToolName, CheckoutDate, EmpID) VALUES (?, ?, ?, ?)" );
     query.addBindValue(last);
    query.addBindValue(tool);
    query.addBindValue(date);
    query.addBindValue(badge);

    {
        if(query.exec())
        {
            QMessageBox::information(this, "Save","Database updated!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Update Failed!");
        }
    }
}

void tools::on_pushButton_delete_tool_clicked()
{

    // Delete selected row using badge number //
    QString badge;
    badge=ui->lineEdit_badge_tools->text();
    QSqlQuery query;
    query.prepare("DELETE FROM Tool WHERE EmpID='"+badge+"'");

    {
        if(query.exec())
        {

            QMessageBox::information(this, "Delete","Database updated!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Delete Failed!");
        }
    }
}

void tools::on_pushButton_loadTable_tool_clicked()
{
    LoginPage conn;

    // Refresh tool database //
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM tool");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    qDebug() << (model->rowCount());

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();

}

void tools::on_pushButton_edit_tool_clicked()
{
    //Update tool database //
    QString last, tool, checkout, badge;
    last=ui->lineEdi_LName->text();
    tool=ui->lineEdit_toolName->text();
    checkout=ui->lineEdit_checkout->text();
    badge=ui->lineEdit_badge_tools->text();

    QSqlQuery query;
    query.prepare("UPDATE Tool SET LastName='"+last+"', ToolName='"+tool+"',CheckOutDate='"+checkout+"', EmpID='"+badge+"' WHERE EmpID='"+badge+"'");
    {
        if(query.exec())
        {

            QMessageBox::information(this, "Save","Database updated!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Update Failed!");
        }
    }
}

void tools::on_pushButton_Hback_clicked()
{
    // Go back to main menu //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}
