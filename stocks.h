#ifndef STOCKS_H
#define STOCKS_H

#include <QDialog>
#include<QtSql>
#include <QtDebug>
#include<QFileInfo>

namespace Ui {
class Stocks;
}

class Stocks : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb2;
    void connClose(){
        mydb2.close();
        mydb2.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        mydb2 = QSqlDatabase::addDatabase("QSQLITE") ;
       mydb2.setDatabaseName("C:/Users/Sandeep/Desktop/PharmaCOre/Pharma.db");
       if(!mydb2.open()){
           qDebug()<<("Database failed to connect");
           return false;
       }
       else {
        qDebug()<<("Database connected");
        return true;
}
    }

public:
    explicit Stocks(QWidget *parent = nullptr);
    ~Stocks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_entrybtn_clicked();

    void on_pushButton_drdisplay_clicked();

    void on_pushButton_updbtn_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Stocks *ui;

};

#endif // STOCKS_H
