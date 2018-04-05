#include "hrmain.h"
#include "ui_hrmain.h"
#include "employeemainmenu.h"
#include "tableeditor.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QApplication>

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
    view->show();

}


void hrMain::on_pushButton_clicked()
{
    // connect line edits with pushbutton to populate the database
}
