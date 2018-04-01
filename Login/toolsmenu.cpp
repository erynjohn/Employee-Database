#include "toolsmenu.h"
#include "ui_toolsmenu.h"

toolsMenu::toolsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::toolsMenu)
{
    ui->setupUi(this);
}

toolsMenu::~toolsMenu()
{
    delete ui;
}
