#ifndef EMPLOYEEMAINMENU_H
#define EMPLOYEEMAINMENU_H

#include <QDialog>
#include "hrmain.h"

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

private:
    Ui::EmployeeMainMenu *ui;
    // Object of class //
    hrMain *hrmain;

};

#endif // EMPLOYEEMAINMENU_H
