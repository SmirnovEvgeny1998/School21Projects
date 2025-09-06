#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private slots:
  void calculator_buttons();

  void on_button_result_clicked();

  void on_button_change_parametrs_clicked();

  void on_button_show_graph_clicked();

  void on_button_clear_graph_clicked();

  void on_credit_calculator_clicked();

  void on_deposit_calculator_clicked();

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;

  QVector<double> x, y;
};
#endif  // CALC_CONTROLLER_H
