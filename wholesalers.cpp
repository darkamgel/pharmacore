#include "wholesalers.h"
#include "ui_wholesalers.h"
#include "dashboard.h"
#include "stocks.h"
#include<QMessageBox>
#include <QDebug>
Wholesalers::Wholesalers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wholesalers)
{
    ui->setupUi(this);

}

Wholesalers::~Wholesalers()
{
    delete ui;
}

void Wholesalers::on_pushButton_back_clicked()
{
    hide();
    Dashboard d;
    d.setModal(true);
    d.exec();
}

void Wholesalers::on_pushButton_suppentry_clicked()
{
    Stocks s;
 QString wid,wname,waddress,wphone,wemail,wmedsupply;
 wid = ui->lineEdit_id->text();
 wname= ui->lineEdit_supname->text()    ;
 waddress = ui->lineEdit_address->text();
    wphone = ui->lineEdit_supphn->text();
    wemail = ui->lineEdit_supemail->text();
    wmedsupply = ui->lineEdit_medsup->text();

    if(!s.connOpen()){
        qDebug()<<"connection failed";
    }
    s.connOpen();
    QSqlQuery qrys;
    qrys.prepare("insert into table_supplier(sid,sname,saddress,sphone,semail,smedsupply) values('"+wid+"','"+wname+"','"+waddress+"','"+wphone+"','"+wemail+"','"+wmedsupply+"')");
    if(qrys.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        s.connClose();
    }else{
        QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
}

}

void Wholesalers::on_pushButton_disp_clicked()
{
    Stocks s;
    QSqlQueryModel *m = new QSqlQueryModel();
    s.connOpen();
    QSqlQuery *qry = new QSqlQuery(s.mydb2);
    qry->prepare("select *from table_supplier");
    qry->exec();
    m->setQuery(*qry);
    ui->tableView->setModel(m);
    s.connClose();
    qDebug() <<( m->rowCount());


}

void Wholesalers::on_pushButton_delsupplier_clicked()
{
    Stocks s;
    QString wid;
            wid = ui->lineEdit_id->text();

            if(!s.connOpen()){
                qDebug()<<"connection failed";
            }
            s.connOpen();
            QSqlQuery qrys;
            qrys.prepare("delete from table_supplier where sid='"+wid+"'");
            if(qrys.exec()){
                QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
                s.connClose();
            }else{
                QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
            }

}
