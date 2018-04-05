#ifndef HRMAIN_H
#define HRMAIN_H
#include <QDialog>

namespace Ui {
class hrMain;
}

class hrMain : public QDialog
{
    Q_OBJECT

public:
    explicit hrMain(QWidget *parent = 0);
    ~hrMain();

private slots:
    void on_pushButton_Hback_clicked();

    void on_pushButton_loadTable_clicked();

    void on_pushButton_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_save_clicked();

    void on_lineEdit_EmpID_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::hrMain *ui;
};

#endif // HRMAIN_H
