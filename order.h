#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include<QtSql>
#include <QtDebug>
#include<QFileInfo>
#include "stocks.h"
namespace Ui {
class order;
}

class order : public QDialog
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
    ~order();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_oentry_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_dentry_clicked();

private:
    Ui::order *ui;
    QSqlDatabase mydb1;
};

#endif // ORDER_H
