#include "warehouse.h"
#include "ui_warehouse.h"
#include "employeemainmenu.h"
#include "loginpage.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>

warehouse::warehouse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warehouse)

{
    ui->setupUi(this);

}

warehouse::~warehouse()
{
    delete ui;
}
void warehouse::on_pushButton_Wback_clicked()
{

    // hide old window and show new window from object //
        this->hide();
        EmployeeMainMenu empMenu;
        empMenu.setModal(true);
        empMenu.exec();
}
void warehouse::on_pushButton_save_WT_clicked()
{
    //Save info into warehouse database//
    QString LNumber, ID, material, status;
    LNumber=ui->lineEdit_LineNumber->text();
    material=ui->lineEdit_material_WT->text();
    ID=ui->lineEdit_warehouseID_WT->text();
    status=ui->lineEdit_status_WT->text();

    QSqlQuery query;
    query.prepare( "INSERT INTO Warehouses (LineNumber, WarehouseID, Material, Status) VALUES (?, ?, ?, ?)" );
     query.addBindValue(LNumber);
    query.addBindValue(ID);
    query.addBindValue(material);
    query.addBindValue(status);

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

void warehouse::on_pushButton_Refresh_WT_clicked()
{
    LoginPage conn;

    // Refresh tool database //
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.db);

    qry->prepare("SELECT * FROM Warehouses");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    qDebug() << (model->rowCount());

    QTableView *view = new QTableView;
    view->setModel(model);
    view->resizeColumnsToContents();
}

void warehouse::on_pushButton_delete_WT_clicked()
{
    // Delete selected row using badge number //
    QString LNumber;
    LNumber=ui->lineEdit_LineNumber->text();
    QSqlQuery query;
    query.prepare("DELETE FROM Warehouses WHERE LineNumber='"+LNumber+"'");

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

void warehouse::on_pushButton_Update_WT_clicked()
{
    //Update warehouse database //
    QString ID, material, status, LNumber;
    LNumber=ui->lineEdit_LineNumber->text();
    ID=ui->lineEdit_warehouseID_WT->text();
    material=ui->lineEdit_material_WT->text();
    status=ui->lineEdit_status_WT->text();

    QSqlQuery query;
    query.prepare("UPDATE Warehouses SET WarehouseID='"+ID+"', Material='"+material+"',Status='"+status+"' WHERE LineNumber='"+LNumber+"'");
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
