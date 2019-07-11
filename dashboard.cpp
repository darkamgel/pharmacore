#include "dashboard.h"
#include "ui_dashboard.h"
#include "wholesalers.h"
#include "stocks.h"
#include "order.h"
#include "regular.h"
#include "selldetails.h"
Dashboard::Dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_wholesale_clicked()
{
    hide();
    Wholesalers w ;
    w.setModal(true);
    w.exec();
}

void Dashboard::on_pushButton_stock_clicked()
{
    hide();
    Stocks s1;
    s1.setModal(true);
    s1.exec();
}

void Dashboard::on_pushButton_order_clicked()
{
    hide();
    order o1;
    o1.setModal(true);
    o1.exec();

}

void Dashboard::on_pushButton_regular_clicked()
{
    hide();
    regular r;
    r.setModal(true);
    r.exec();
}

void Dashboard::on_pushButton_selldetails_clicked()
{
    hide();
    selldetails s;
    s.setModal(true);
    s.exec();
}
