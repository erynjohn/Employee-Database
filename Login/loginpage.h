#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "employeemainmenu.h"
#include "hrmain.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = 0);
    ~LoginPage();

private slots:
    void on_login_clicked();

private:
    Ui::LoginPage *ui;
    // object of class //
    EmployeeMainMenu *employeeMainMenu;

};

#endif // LOGINPAGE_H
