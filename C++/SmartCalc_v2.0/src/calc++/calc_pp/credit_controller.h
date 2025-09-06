#ifndef CREDIT_CONTROLLER_H
#define CREDIT_CONTROLLER_H

#include <QDialog>
#include <QMessageBox>
#include <QRegularExpression>

#include "credit_model.h"

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_calculate_credit_clicked();

 private:
  Ui::Credit *ui;
};

#endif  // CREDIT_CONTROLLER_H
