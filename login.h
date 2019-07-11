#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "dashboard.h"
#include<QtSql>
#include <QtDebug>
#include<QFileInfo>
#include "stocks.h"
namespace Ui {
class LOGIN;
}

class LOGIN : public QMainWindow
{
    Q_OBJECT
public:



public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LOGIN *ui;
    Dashboard *dsh;
    QSqlDatabase mydb;


};

#endif // LOGIN_H
