#ifndef EMPLOYEEMAINMENU_H
#define EMPLOYEEMAINMENU_H

#include <QDialog>
#include "hrmain.h"
#include "tools.h"
#include "warehouse.h"

namespace Ui {
class EmployeeMainMenu;
}

class EmployeeMainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeMainMenu(QWidget *parent = 0);
    ~EmployeeMainMenu();

private slots:
    void on_pushButton_HR_clicked();

    void on_pushButton_Tools_clicked();

    void on_pushButton_warehouse_clicked();

    void on_pushButton_logout_clicked();

private:
    Ui::EmployeeMainMenu *ui;
};

#endif // EMPLOYEEMAINMENU_H
