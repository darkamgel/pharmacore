#include "stocks.h"
#include "ui_stocks.h"
#include "dashboard.h"
#include <QDebug>
#include<QDate>
#include<QMessageBox>
#include<math.h>
Stocks::Stocks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stocks)
{
    ui->setupUi(this);

}

Stocks::~Stocks()
{
    delete ui;
}

void Stocks::on_pushButton_clicked()
{
    hide();
    Dashboard d1;
    d1.setModal(true);
    d1.exec();
}

void Stocks::on_pushButton_entrybtn_clicked()
{
    QString drid,drname,drcmpny,drqnty,drpri,drsentry,drexpdate,drtype;
            drid = ui->lineEdit_did->text();
            drname = ui->lineEdit_dname->text();
            drcmpny = ui->lineEdit_cmpny->text();
            drqnty = ui->lineEdit_qntty->text();
            drpri = ui->lineEdit_price->text();
            drsentry = ui->dateEdit_sdentry->date().toString("dd/MM/yyyy");
            drexpdate = ui->dateEdit_edentry->date().toString("dd/MM/yyyy");
            drtype = ui->lineEdit_dtype->text();
            //drcp= ui->lineEdit_cp->text();
           // drcp=drqnty*drpri
            if(!connOpen()){
                qDebug()<<"connection failed";
            }
            connOpen();
            QSqlQuery qrys;
            qrys.prepare("insert into table_stock(did,dname,dcmpny,dqnty,dprice,dsenty,dexpiry,dtype,dcp) values('"+drid+"','"+drname+"','"+drcmpny+"','"+drqnty+"','"+drpri+"','"+drsentry+"','"+drexpdate+"','"+drtype+"','"(+drqnty*drpri)+"')");
            if(qrys.exec()){
                QMessageBox::critical(this,tr("Save"),tr("Saved"));
                connClose();
            }else{
                QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
            }
}

void Stocks::on_pushButton_drdisplay_clicked()
{
    Stocks s;
    QSqlQueryModel *m = new QSqlQueryModel();
    connOpen();
    QSqlQuery *qry = new QSqlQuery(s.mydb2);
    qry->prepare("select *from table_stock");
    qry->exec();
    m->setQuery(*qry);
    ui->tableView->setModel(m);
    connClose();
    qDebug() <<( m->rowCount());
}

void Stocks::on_pushButton_updbtn_clicked()
{
    QString drid,drname,drcmpny,drqnty,drpri,drsentry,drexpdate,drtype,drcp;
            drid = ui->lineEdit_did->text();
            drname = ui->lineEdit_dname->text();
            drcmpny = ui->lineEdit_cmpny->text();
            drqnty = ui->lineEdit_qntty->text();
            drpri = ui->lineEdit_price->text();
            drsentry = ui->dateEdit_sdentry->date().toString("dd/MM/yyyy");
            drexpdate = ui->dateEdit_edentry->date().toString("dd/MM/yyyy");
            drtype = ui->lineEdit_dtype->text();
             drcp= ui->lineEdit_cp->text();
            if(!connOpen()){
                qDebug()<<"connection failed";
            }
            connOpen();
            QSqlQuery qrys;
            qrys.prepare("update table_stock set did= '"+drid+"',dname='"+drname+"',dcmpny='"+drcmpny+"',dqnty='"+drqnty+"',dprice='"+drpri+"',dsenty='"+drsentry+"',dexpiry='"+drexpdate+"',dtype='"+drtype+",'dcp='"+drcp+"'where did='"+drid+"'");
            if(qrys.exec()){
                QMessageBox::critical(this,tr("Edit"),tr("Updated"));
                connClose();
            }else{
                QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
            }
}

void Stocks::on_pushButton_2_clicked()
{
    QString drid,drname,drcmpny,drqnty,drpri,drsentry,drexpdate,drtype;
            drid = ui->lineEdit_did->text();

            if(!connOpen()){
                qDebug()<<"connection failed";
            }
            connOpen();
            QSqlQuery qrys;
            qrys.prepare("delete from table_stock where did='"+drid+"'");
            if(qrys.exec()){
                QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
                connClose();
            }else{
                QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
            }

}
