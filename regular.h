#ifndef REGULAR_H
#define REGULAR_H
#include "stocks.h"
#include <QDialog>

namespace Ui {
class regular;
}

class regular : public QDialog
{
    Q_OBJECT

public:
    explicit regular(QWidget *parent = nullptr);
    ~regular();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_back_2_clicked();

    void on_pushButton_back_4_clicked();

private:
    Ui::regular *ui;
};

#endif // REGULAR_H
