#include "credit_controller.h"

#include "ui_credit_view.h"

Credit::Credit(QWidget *parent) : QDialog(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
}

Credit::~Credit() {
  delete ui;
  //на 39 строке идет сравнение с "0" но при 00000 или научной нотации он не
  //сработает, переделать
}

void Credit::on_calculate_credit_clicked() {
  int annuitent = 0, differential = 0;
  double monthly_payment = 0, overpayment = 0, full_summ = 0;
  QString montly_payment_str, overpayment_str, full_summ_str;
  QString amount_str = ui->summ->text();
  QString lengrh_str = ui->length->text();
  QString percent_str = ui->percent->text();
  double amount = amount_str.toDouble();
  int lengrh = lengrh_str.toInt();
  double percent = percent_str.toDouble();
  s21::credit_controller cred_c;

  if (ui->annual->isChecked()) {
    annuitent = 1;
    differential = 0;
  } else if (ui->differencial->isChecked()) {
    annuitent = 0;
    differential = 1;
  }
  if (amount_str.length() == 0 || lengrh_str.length() == 0 ||
      percent_str.length() == 0) {
    QMessageBox::warning(this, "Just no", "Fulfill the lines.");
  } else if ((amount == 0 && amount_str.contains(QRegularExpression("[^0]"))) ||
             (lengrh == 0 && lengrh_str.contains(QRegularExpression("[^0]"))) ||
             (percent == 0 &&
              percent_str.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Wrong characters.");
  } else if (lengrh > 600 || lengrh == 0) {
    QMessageBox::warning(
        this, "Just no",
        "No more than 50 years of credit and at least 1 month.");
  } else if (percent <= 0) {
    QMessageBox::warning(this, "Just no",
                         "Percent must be positive number more than 0.");
  } else if (annuitent == 1) {
    monthly_payment =
        cred_c.s21_bank_annuitent_montly_payment(amount, lengrh, percent);
    montly_payment_str = QString::number(monthly_payment, 'f', 2);
    ui->montly_percent->setText(montly_payment_str);

    overpayment =
        cred_c.s21_bank_annuitent_overpayment(amount, lengrh, percent);
    overpayment_str = QString::number(overpayment, 'f', 2);
    ui->alltime_percent->setText(overpayment_str);

    full_summ = cred_c.s21_bank_annuitent_all_payment(amount, lengrh, percent);
    full_summ_str = QString::number(full_summ, 'f', 2);

    ui->full_credit_summ->setText(full_summ_str);
  } else if (differential == 1) {
    monthly_payment = cred_c.s21_bank_differential_montly_payment_first(
        amount, lengrh, percent);
    montly_payment_str = QString::number(monthly_payment, 'f', 2);
    montly_payment_str += " - ";
    monthly_payment = cred_c.s21_bank_differential_montly_payment_last(
        amount, lengrh, percent);
    montly_payment_str += QString::number(monthly_payment, 'f', 2);
    ui->montly_percent->setText(montly_payment_str);

    overpayment =
        cred_c.s21_bank_differential_overpayment(amount, lengrh, percent);
    overpayment_str = QString::number(overpayment, 'f', 2);
    ui->alltime_percent->setText(overpayment_str);

    full_summ =
        cred_c.s21_bank_differential_all_payment(amount, lengrh, percent);
    full_summ_str = QString::number(full_summ, 'f', 2);
    ui->full_credit_summ->setText(full_summ_str);
  } else {
    QMessageBox::warning(this, "Just no", "Choose type.");
  }
}
