#include "selldetails.h"
#include "ui_selldetails.h"
#include "dashboard.h"

selldetails::selldetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selldetails)
{
    ui->setupUi(this);
}

selldetails::~selldetails()
{
    delete ui;
}

void selldetails::on_pushButton_back_clicked()
{
    hide();
    Dashboard d;
    d.setModal(true);
    d.exec();
}
