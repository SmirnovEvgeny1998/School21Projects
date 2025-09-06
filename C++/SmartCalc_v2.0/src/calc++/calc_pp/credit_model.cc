#include "credit_model.h"

s21::credit_controller::credit_controller() {}

double s21::credit_controller::s21_bank_annuitent_montly_payment(
    double credit_summ, int length_month, double percent) {
  double result = 0, percent_stavka = 0;
  percent_stavka = percent / 1200;
  result = credit_summ *
           (percent_stavka / (1 - pow(1 + percent_stavka, length_month * -1)));
  return result;
}

double s21::credit_controller::s21_bank_annuitent_overpayment(
    double credit_summ, int length_month, double percent) {
  credit_controller cred_c;
  double montly = 0, result = 0;
  montly = cred_c.s21_bank_annuitent_montly_payment(credit_summ, length_month,
                                                    percent);
  result = (montly * length_month) - credit_summ;
  return result;
}

double s21::credit_controller::s21_bank_annuitent_all_payment(
    double credit_summ, int length_month, double percent) {
  credit_controller cred_c;
  double montly = 0, result = 0;
  montly = cred_c.s21_bank_annuitent_montly_payment(credit_summ, length_month,
                                                    percent);
  result = montly * length_month;
  return result;
}

double s21::credit_controller::s21_bank_differential_montly_payment_first(
    double credit_summ, int length_month, double percent) {
  double result = 0, percent_stavka = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  result = credit_summ / length_month + percent_stavka;
  return result;
}

double s21::credit_controller::s21_bank_differential_montly_payment_last(
    double credit_summ, int length_month, double percent) {
  double result = 0, percent_stavka = 0, difference = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  difference = credit_summ / length_month;
  result = difference + percent_stavka;
  credit_summ -= difference;
  for (int i = 1; i < length_month; i++) {
    percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
    result = difference + percent_stavka;
    credit_summ -= difference;
  }
  return result;
}

double s21::credit_controller::s21_bank_differential_overpayment(
    double credit_summ, int length_month, double percent) {
  credit_controller cred_c;
  double result = 0, all = 0;
  all = cred_c.s21_bank_differential_all_payment(credit_summ, length_month,
                                                 percent);
  result = all - credit_summ;
  return result;
}

double s21::credit_controller::s21_bank_differential_all_payment(
    double credit_summ, int length_month, double percent) {
  double result = 0, percent_stavka = 0, difference = 0;
  percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
  difference = credit_summ / length_month;
  result = difference + percent_stavka;
  credit_summ -= difference;
  for (int i = 1; i < length_month; i++) {
    percent_stavka = (credit_summ * (percent / 100) * 30.416666) / 365;
    result += difference + percent_stavka;
    credit_summ -= difference;
  }
  return result;
}
