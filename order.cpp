#include "order.h"
#include "ui_order.h"
#include "dashboard.h"
#include "stocks.h"
#include <QDebug>
#include<QDate>
#include<QMessageBox>
order::order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);

}

order::~order()
{
    delete ui;
}

void order::on_pushButton_clicked()
{
    hide();
    Dashboard d2;
    d2.setModal(true);
    d2.exec();

}

void order::on_pushButton_oentry_clicked()
{
    Stocks s;
 QString orid,odname,ocmpnyname,orsupplier,oquntity,ocprice,oddate,ordtype;
 orid = ui->lineEdit_oid->text();
 odname= ui->lineEdit_oname->text()    ;
 ocmpnyname = ui->lineEdit_ocmpname->text();
    orsupplier = ui->lineEdit_osupname->text();
    oquntity = ui->lineEdit_oqnty->text();
    ocprice = ui->lineEdit_ocst->text();
    oddate = ui->dateEdit_od->date().toString("dd/MM/yyyy");
    ordtype = ui->lineEdit_otype->text();
    if(!s.connOpen()){
        qDebug()<<"connection failed";
    }
    s.connOpen();
    QSqlQuery qrys;
    qrys.prepare("insert into table_order(oid,dname,ocompny,osupplier,oqnty,ocprice,odate,odtype) values('"+orid+"','"+odname+"','"+ocmpnyname+"','"+orsupplier+"','"+oquntity+"','"+ocprice+"','"+oddate+"','"+ordtype+"')");
    if(qrys.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        s.connClose();
    }else{
        QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
}

}

void order::on_pushButton_2_clicked()
{
    Stocks s;
    QSqlQueryModel *m = new QSqlQueryModel();
    s.connOpen();
    QSqlQuery *qry = new QSqlQuery(s.mydb2);
    qry->prepare("select *from table_order");
    qry->exec();
    m->setQuery(*qry);
    ui->tableView->setModel(m);
    s.connClose();
    qDebug() <<( m->rowCount());

}

void order::on_pushButton_dentry_clicked()
{
    Stocks s;
    QString orid;
            orid = ui->lineEdit_oid->text();

            if(!s.connOpen()){
                qDebug()<<"connection failed";
            }
            s.connOpen();
            QSqlQuery qrys;
            qrys.prepare("delete from table_order where oid='"+orid+"'");
            if(qrys.exec()){
                QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
                s.connClose();
            }else{
                QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
            }

}
