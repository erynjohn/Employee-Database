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

private:
    Ui::hrMain *ui;
};

#endif // HRMAIN_H
