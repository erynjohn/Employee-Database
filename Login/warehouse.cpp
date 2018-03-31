#include "warehouse.h"
#include "ui_warehouse.h"
#include "employeemainmenu.h"
#include "loginpage.h"

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


//SELECT [WarehouseID],[WarehouseAddress] FROM [GbManuf][dbo].[InventoryWarehouse]
