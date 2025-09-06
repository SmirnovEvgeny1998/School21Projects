#include "deposit_controller.h"

#include "ui_deposit_view.h"

deposit::deposit(QWidget *parent) : QDialog(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
}

deposit::~deposit() { delete ui; }

void deposit::on_button_add_repelishment_clicked() {
  int counter = ui->list_of_repelishment->count();
  QString add_summ_data = ui->repelishment_summ->text();
  if (ui->repelishment_summ->text().length() == 0) {
    QMessageBox::warning(this, "Just no", "Fulfill the amount.");
  } else if (add_summ_data.toDouble() == 0 &&
             add_summ_data.contains(QRegularExpression("[^0]"))) {
    QMessageBox::warning(this, "Just no", "Wrong characters.");
  } else if (counter >= 10) {
    QMessageBox::warning(this, "Just no", "No more than 10 repelishments.");
  } else {
    add_summ_data = ui->repelishment_month->currentText();
    this->repelishment_months[counter] = ui->repelishment_month->currentText();
    add_summ_data += "M - ";
    add_summ_data += ui->repelishment_year->currentText();
    this->repelishment_years[counter] = ui->repelishment_year->currentText();
    add_summ_data += "Y - ";
    add_summ_data += ui->repelishment_summ->text();
    this->repelishment_summs[counter] = ui->repelishment_summ->text();
    ui->list_of_repelishment->addItem(add_summ_data);
  }
}

void deposit::on_remove_repelishment_clicked() {
  int index = ui->list_of_repelishment->currentIndex();
  ui->list_of_repelishment->removeItem(index);
  for (int i = index; i < 9 && ui->list_of_repelishment->count() > 0; i++) {
    this->repelishment_months[i] = this->repelishment_months[i + 1];
    this->repelishment_years[i] = this->repelishment_months[i + 1];
    this->repelishment_summs[i] = this->repelishment_months[i + 1];
  }
  this->repelishment_months[9] = "";
  this->repelishment_years[9] = "";
  this->repelishment_summs[9] = "";
}

void deposit::on_add_widhrawl_clicked() {
  int counter = ui->list_of_widhrawls->count();
  QString remove_summ_data = ui->widhrawl_summ->text();
  if (ui->widhrawl_summ->text().length() == 0) {
    QMessageBox::warning(this, "Just no", "Fulfill the amount.");
  } else if (remove_summ_data.toDouble() == 0 &&
             remove_summ_data.contains(QRegularExpression("[^0]"))) {
    QMessageBox::warning(this, "Just no", "Wrong characters.");
  } else if (counter >= 10) {
    QMessageBox::warning(this, "Just no", "No more than 10 widhrawls.");
  } else {
    remove_summ_data = ui->widhrawl_month->currentText();
    this->widrawl_months[counter] = ui->widhrawl_month->currentText();
    remove_summ_data += "M - ";
    remove_summ_data += ui->widhrawl_year->currentText();
    this->widrawl_years[counter] = ui->widhrawl_year->currentText();
    remove_summ_data += "Y - ";
    remove_summ_data += ui->widhrawl_summ->text();
    this->widrawl_summs[counter] = ui->widhrawl_summ->text();
    ui->list_of_widhrawls->addItem(remove_summ_data);
  }
}

void deposit::on_remove_widhrawl_clicked() {
  int index = ui->list_of_widhrawls->currentIndex();
  ui->list_of_widhrawls->removeItem(index);
  for (int i = index; i < 9 && ui->list_of_widhrawls->count() > 0; i++) {
    this->widrawl_months[i] = this->widrawl_months[i + 1];
    this->widrawl_years[i] = this->widrawl_months[i + 1];
    this->widrawl_summs[i] = this->widrawl_months[i + 1];
  }
  this->widrawl_months[9] = "";
  this->widrawl_years[9] = "";
  this->widrawl_summs[9] = "";
}

void deposit::on_button_calculate_deposit_clicked() {
  double percents = 0, tax = 0, end_summ = 0;
  int capitalization = 0, deposit_periodisity = 0, repelishment_counter = 0,
      widhrawl_counter = 0;
  s21::deposit_controller::s21_repelishments rep[50] = {0};
  s21::deposit_controller::s21_widrawls wid[50] = {0};
  QString deposit_summ_str = ui->deposit_summ->text();
  QString deposit_length_str = ui->deposit_length->text();
  QString deposit_percent_str = ui->percent_deposit->text();
  QString stavka_CB_str = ui->CB_stavka->text();
  double deposit_summ = deposit_summ_str.toDouble();
  int deposit_length = deposit_length_str.toInt();
  double deposit_percent = deposit_percent_str.toDouble();
  double stavka_CB = stavka_CB_str.toDouble();

  deposit_periodisity = ui->deposit_periodicity->currentIndex();
  if (ui->capitalization->isChecked()) {
    capitalization = 1;
  } else {
    capitalization = 0;
  }
  repelishment_counter = ui->list_of_repelishment->count();
  widhrawl_counter = ui->list_of_widhrawls->count();
  for (int i = 0; i < repelishment_counter; i++) {
    rep[i].month = this->repelishment_months[i].toInt();
    rep[i].year = this->repelishment_years[i].toInt();
    rep[i].summ = this->repelishment_summs[i].toDouble();
  }
  for (int i = 0; i < widhrawl_counter; i++) {
    wid[i].month = this->widrawl_months[i].toInt();
    wid[i].year = this->widrawl_years[i].toInt();
    wid[i].summ = this->widrawl_summs[i].toDouble();
  }
  if (repelishment_counter == 0) {
    rep[0].day = 0;
    rep[0].month = 0;
    rep[0].year = 0;
    rep[0].summ = 0;
    rep[0].last = 1;
  } else {
    rep[repelishment_counter - 1].last = 1;
  }
  if (widhrawl_counter == 0) {
    wid[0].day = 0;
    wid[0].month = 0;
    wid[0].year = 0;
    wid[0].summ = 0;
    wid[0].last = 1;
  } else {
    wid[widhrawl_counter - 1].last = 1;
  }
  if (deposit_summ_str.length() == 0 || deposit_percent_str.length() == 0 ||
      deposit_length_str.length() == 0 || stavka_CB_str.length() == 0) {
    QMessageBox::warning(this, "Just no", "Fulfill the lines.");
  } else if ((deposit_summ_str.toDouble() == 0 &&
              deposit_summ_str.contains(QRegularExpression("[^0]"))) ||
             (deposit_length_str.toDouble() == 0 &&
              deposit_length_str.contains(QRegularExpression("[^0]"))) ||
             (deposit_percent_str.toDouble() == 0 &&
              deposit_percent_str.contains(QRegularExpression("[^0]"))) ||
             (stavka_CB_str.toDouble() == 0 &&
              stavka_CB_str.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Wrong characters.");
  } else if (deposit_length > 600 || deposit_length <= 0) {
    QMessageBox::warning(
        this, "Just no",
        "No more than 50 years of deposit and at least 1 month.");
  } else if (stavka_CB <= 0 || deposit_percent <= 0) {
    QMessageBox::warning(
        this, "Just no",
        "Percents and CB must be positive numbers more than 0.");
  } else {
    percents = s21::deposit_controller::s21_deposit_profitability_complex(
        0, deposit_summ, deposit_length, deposit_percent, 13,
        deposit_periodisity, capitalization, rep, wid, stavka_CB);
    tax = s21::deposit_controller::s21_deposit_profitability_complex(
        1, deposit_summ, deposit_length, deposit_percent, 13,
        deposit_periodisity, capitalization, rep, wid, stavka_CB);
    end_summ = s21::deposit_controller::s21_deposit_profitability_complex(
        2, deposit_summ, deposit_length, deposit_percent, 13,
        deposit_periodisity, capitalization, rep, wid, stavka_CB);
    if (percents < 0 || tax < 0 || end_summ < 0) {
      QMessageBox::warning(this, "Just no",
                           "Widhrawl amount is bigger than deposit summ.");
    } else {
      ui->final_percent->setText(QString::number(percents, 'f', 2));
      ui->tax->setText(QString::number(tax, 'f', 2));
      ui->final_deposit_summ->setText(QString::number(end_summ, 'f', 2));
    }
  }
}
