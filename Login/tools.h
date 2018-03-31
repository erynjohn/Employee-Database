#ifndef TOOLS_H
#define TOOLS_H

#include <QDialog>

namespace Ui {
class tools;
}

class tools : public QDialog
{
    Q_OBJECT

public:
    explicit tools(QWidget *parent = 0);
    ~tools();

private slots:
    void on_pushButton_Tback_clicked();

private:
    Ui::tools *ui;
};

#endif // TOOLS_H
