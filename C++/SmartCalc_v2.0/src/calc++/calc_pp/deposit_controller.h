#ifndef DEPOSIT_CONTROLLER_H
#define DEPOSIT_CONTROLLER_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>

#include "deposit_model.h"

namespace Ui {
class deposit;
}

class deposit : public QDialog {
  Q_OBJECT

 public:
  explicit deposit(QWidget *parent = nullptr);
  ~deposit();
  QString repelishment_months[10];
  QString repelishment_years[10];
  QString repelishment_summs[10];
  QString widrawl_months[10];
  QString widrawl_years[10];
  QString widrawl_summs[10];

 private slots:
  void on_button_add_repelishment_clicked();

  void on_remove_repelishment_clicked();

  void on_add_widhrawl_clicked();

  void on_remove_widhrawl_clicked();

  void on_button_calculate_deposit_clicked();

 private:
  Ui::deposit *ui;
};

#endif  // DEPOSIT_CONTROLLER_H
