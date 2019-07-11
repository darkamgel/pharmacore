#ifndef SELLDETAILS_H
#define SELLDETAILS_H

#include <QDialog>

namespace Ui {
class selldetails;
}

class selldetails : public QDialog
{
    Q_OBJECT

public:
    explicit selldetails(QWidget *parent = nullptr);
    ~selldetails();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::selldetails *ui;
};

#endif // SELLDETAILS_H
