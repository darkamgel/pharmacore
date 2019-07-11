#include "regular.h"
#include "ui_regular.h"
#include "dashboard.h"
#include "stocks.h"
#include<QDebug>
#include<QMessageBox>

regular::regular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regular)
{
    ui->setupUi(this);
}

regular::~regular()
{
    delete ui;
}

void regular::on_pushButton_back_clicked()
{
    hide();
    Dashboard d;
    d.setModal(true);
    d.exec();
}

void regular::on_pushButton_back_2_clicked()
{
    Stocks s;
 QString rid,rname,rdname,rphmn,rcost,rdue,raddress;
 rid = ui->lineEdit_id->text();
  rname = ui->lineEdit_name->text()    ;
 rdname = ui->lineEdit_dname->text();
    rphmn = ui->lineEdit_phone->text();
    rcost = ui->lineEdit_cost->text();
    rdue = ui->lineEdit_due->text();
    raddress = ui->lineEdit_address->text();

    if(!s.connOpen()){
        qDebug()<<"connection failed";
    }
    s.connOpen();
    QSqlQuery qrys;
    qrys.prepare("insert into table_regular(id,name,drug_name,phone_number,cost,due,address) values('"+rid+"','"+rname+"','"+rdname+"','"+rphmn+"','"+rcost+"','"+rdue+"','"+raddress+"')");
    if(qrys.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        s.connClose();
    }else{
        QMessageBox::critical(this,tr("error::"),qrys.lastError().text());
}

}

void regular::on_pushButton_back_4_clicked()
{
    Stocks s;
    QSqlQueryModel *m = new QSqlQueryModel();
    s.connOpen();
    QSqlQuery *qry = new QSqlQuery(s.mydb2);
    qry->prepare("select *from table_regular");
    qry->exec();
    m->setQuery(*qry);
    ui->tableView->setModel(m);
    s.connClose();
    qDebug() <<( m->rowCount());
}
