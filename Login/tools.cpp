#include "tools.h"
#include "ui_tools.h"
#include "employeemainmenu.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QDate>

tools::tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tools)
{
    ui->setupUi(this);
    refreshtable();
}

tools::~tools()
{
    delete ui;
}

void tools::on_pushButton_save_tool_clicked()
{
    //Save info into tool database//
    QString line, empid, lname, toolname;
    line=ui->lineEdit_linenum->text();
    empid=ui->lineEdit_ID->text();
    lname=ui->lineEdi_LName->text();
    toolname=ui->lineEdit_toolName->text();
    QDate date = QDate::currentDate();
    ui->dateEdit_tool->setDate(date);


    QSqlQuery query;
    query.prepare( "INSERT INTO Tool (LineNumber, EmpID, LName, ToolName, CheckoutDate) VALUES (?, ?, ?, ?, ?)" );
    query.addBindValue(line);
     query.addBindValue(empid);
    query.addBindValue(lname);
    query.addBindValue(toolname);
    query.addBindValue(date);

    {
        if(!query.exec())
        {
            QMessageBox::warning(this, "Error", "Duplicate ID or Line Item!");
        }
    }
    refreshtable();
}

void tools::on_pushButton_delete_tool_clicked()
{

    // Delete selected row using badge number //
    QString line;
    line=ui->lineEdit_linenum_delete->text();
    QSqlQuery query;
    query.prepare("DELETE FROM Tool WHERE LineNumber='"+line+"'");

    {
        if(!query.exec())
        {
            QMessageBox::warning(this, "Error", "Duplicate ID or Line Item!");
        }
        refreshtable();
    }
}

void tools::refreshtable()
{
    LoginPage conn;

    // Refresh tool database //
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Tool");
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
    QString line, last, tool, badge;
    last=ui->lineEdi_LName->text();
    badge=ui->lineEdit_ID->text();
    line=ui->lineEdit_linenum->text();
    tool=ui->lineEdit_toolName->text();



    QSqlQuery query;
    query.prepare("UPDATE Tool SET LineNumber='"+line+"', LName='"+last+"', ToolName='"+tool+"', EmpID='"+badge+"' WHERE LineNumber='"+line+"'");
    {
        if(!query.exec())
        {
            QMessageBox::warning(this, "Error", "Duplicate ID or Line Item!");
        }
    }
    refreshtable();
}

void tools::on_pushButton_Hback_clicked()
{
    // Go back to main menu //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}
