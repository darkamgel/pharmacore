#ifndef WHOLESALERS_H
#define WHOLESALERS_H

#include <QDialog>
#include<QtSql>
#include <QtDebug>
#include<QFileInfo>
#include "stocks.h"

namespace Ui {
class Wholesalers;
}

class Wholesalers : public QDialog
{
    Q_OBJECT

public:
    explicit Wholesalers(QWidget *parent = nullptr);
    ~Wholesalers();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_suppentry_clicked();

    void on_pushButton_disp_clicked();

    void on_pushButton_delsupplier_clicked();

private:
    Ui::Wholesalers *ui;
    QSqlDatabase mydb3;
};

#endif // WHOLESALERS_H
