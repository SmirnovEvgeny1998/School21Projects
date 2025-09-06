#include "credit.h"
#include "ui_credit.h"

#include <QApplication>

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_pushButton_clicked()
{
    /*int annuiment = 0, differential = 0;
    double monthly_payment = 0;
    QString montly_payment_str;
    QString amount_str = ui->amount->text();
    QString lengrh_str = ui->length->text();
    QString percent_str = ui->percent->text();
    double amount = amount_str.toDouble();
    int lengrh = lengrh_str.toInt();
    double percent = percent_str.toDouble();
    if (ui->annuiment->isChecked()) {
        annuiment = 1;
        differential = 0;
    } else if (ui->differential->isChecked()) {
        annuiment = 0;
        differential = 1;
    }
    if (annuiment == 1) {
        monthly_payment =
        montly_payment_str = QString::number(monthly_payment);
        ui->montly_payment->setText(montly_payment_str);
    }*/
}

