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

private:
    Ui::hrMain *ui;
};

#endif // HRMAIN_H
