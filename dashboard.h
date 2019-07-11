#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_pushButton_wholesale_clicked();

    void on_pushButton_stock_clicked();

    void on_pushButton_order_clicked();

    void on_pushButton_regular_clicked();

    void on_pushButton_selldetails_clicked();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
