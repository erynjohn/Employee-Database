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

void tools::on_pushButton_Tback_clicked()
{
    // hide old window and show new window from object //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}


void tools::on_pushButton_save_tool_clicked()
{

    QString badge, last, tool, date;
    last=ui->lineEdit_equip_tools->text();
    tool=ui->lineEdit_badge_tools->text();
    date=ui->lineEdi_LName->text();

    QSqlQuery query;
    query.prepare( "INSERT INTO Tools (BadgeNum, LName, ToolName, CheckoutDate) VALUES (?, ?, ?, ?)" );
     query.addBindValue(last);
    query.addBindValue(tool);
    query.addBindValue(date);

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

void tools::on_pushButton_delete_tool_clicked()
{

}

void tools::on_pushButton_loadTable_tool_clicked()
{
    LoginPage conn;

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Tools");
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
    QString last, tool, checkout, badge;
    last=ui->lineEdit_equip_tools->text();
    tool=ui->lineEdit_equip_tools->text();
    checkout=ui->lineEdit_checkout->text();
    badge=ui->lineEdit_badge_tools->text();

    QSqlQuery query;
    query.prepare("UPDATE Tools SET LName='"+last+"', ToolName='"+tool+"',CheckOutDate='"+checkout+"' badgeNum='"+badge+"' WHERE BadgeNum='"+badge+"'");
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
