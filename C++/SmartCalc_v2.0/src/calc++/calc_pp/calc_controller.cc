#include "calc_controller.h"

#include <QApplication>

#include "calc_model.h"
#include "credit_controller.h"
#include "deposit_controller.h"
#include "ui_calc_view.h"

// The main window to which you add toolbars,
// menubars, widgets and status bar
#include <QtWidgets/QMainWindow>

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->button_0, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_1, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_2, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_3, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_4, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_5, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_6, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_7, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_8, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_9, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_left_br, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_right_br, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_plus, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_minus, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_multiply, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_divide, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_degree, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_ln, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_log, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_mod, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_sin, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_cos, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_tan, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_asin, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_acos, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_atan, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_sqrt, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_x, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_point, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_clear, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  connect(ui->button_delete_letter, &QPushButton::clicked, this,
          &MainWindow::calculator_buttons);
  ui->start_x->setText("0");
  ui->end_x->setText("5");
  ui->start_y->setText("0");
  ui->end_y->setText("5");
  ui->step_width->setText("0.1");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::calculator_buttons() {
  QPushButton *push_button = qobject_cast<QPushButton *>(sender());
  QString string = ui->line_equasion->text();
  if (string.length() > 255) {
    QMessageBox::warning(this, "Just no", "Math is too long");
  } else if (push_button->objectName() == "button_0") {
    string += "0";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_1") {
    string += "1";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_2") {
    string += "2";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_3") {
    string += "3";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_4") {
    string += "4";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_5") {
    string += "5";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_6") {
    string += "6";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_7") {
    string += "7";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_8") {
    string += "8";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_9") {
    string += "9";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_left_br") {
    string += "(";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_right_br") {
    string += ")";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_plus") {
    string += "+";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_minus") {
    string += "-";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_multiply") {
    string += "*";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_divide") {
    string += "/";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_degree") {
    string += "^";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_ln") {
    string += "ln";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_log") {
    string += "log";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_mod") {
    string += "mod";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_sin") {
    string += "sin";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_cos") {
    string += "cos";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_tan") {
    string += "tan";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_asin") {
    string += "asin";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_acos") {
    string += "acos";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_atan") {
    string += "atan";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_sqrt") {
    string += "sqrt";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_x") {
    string += "x";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_point") {
    string += ".";
    ui->line_equasion->setText(string);
  } else if (push_button->objectName() == "button_clear") {
    QString s = ui->line_equasion->text();
    if (!s.isEmpty()) {
      s.resize(0);
    }
    ui->line_equasion->setText(s);
  } else if (push_button->objectName() == "button_delete_letter") {
    QString s = ui->line_equasion->text();
    if (!s.isEmpty()) {
      s.resize(s.size() - 1);
    }
    ui->line_equasion->setText(s);
  }
}

void MainWindow::on_button_result_clicked() {
  if (ui->line_equasion->text().length() > 255) {
    QMessageBox::warning(this, "Just no", "Слишком длинное уравнение.");
  } else {
    QString check = ui->line_equasion->text() + "     ",
            string = ui->line_equasion->text();
    int length = 0;
    bool no_error_b = true;
    s21::calc_controller calc;
    std::string string_std;
    std::string *string_massive_std, *djicstra_massive_std;
    check.replace("e+", "e");
    check.replace("e-", "e");
    int no_error = calc.check_equation_line(check.toStdString(), 1);
    string.replace("--", "++");
    string.replace("++", "+");
    string_std = calc.change_scientific_notation(string.toStdString());
    if (no_error == 0) {
      no_error_b = true;
      string_massive_std = calc.break_string(string_std, &no_error_b, &length);
      if (no_error_b == false) {
        QMessageBox::warning(this, "Just no", "Wrong equasion.");
      }
    } else if (no_error == 1) {
      QMessageBox::warning(this, "Just no", "Пустое уравнение.");
    } else if (no_error == 2) {
      QMessageBox::warning(this, "Just no",
                           "Уравнение начинается с недопустимых знаков.");
    } else if (no_error == 3) {
      QMessageBox::warning(this, "Just no", "Ошибка в записи точки.");
    } else if (no_error == 4) {
      QMessageBox::warning(this, "Just no", "Ошибка в записи скобок.");
    } else if (no_error == 5) {
      QMessageBox::warning(this, "Just no", "Уравнение в неправильной форме.");
    } else if (no_error == 7) {
      QMessageBox::warning(
          this, "Just no",
          "Уравнение с иксом не могут быть вычислены, используйте график.");
    } else if (no_error == 8) {
      QMessageBox::warning(this, "Just no",
                           "Уравнение должно придерживаться формы sin(x).");
    }
    if (no_error == 0) {
      djicstra_massive_std =
          calc.string_to_djicstra(string_massive_std, length);
      double result = calc.calculation(djicstra_massive_std, length);
      ui->line_equasion->setText(QString::number(result));
    }
  }
}

void MainWindow::on_button_change_parametrs_clicked() {
  QString height_l = ui->start_y->text();
  QString height_h = ui->end_y->text();
  QString width_l = ui->start_x->text();
  QString width_h = ui->end_x->text();
  QString step = ui->step_width->text();

  if (height_l.length() == 0 || height_h.length() == 0 ||
      width_l.length() == 0 || width_h.length() == 0 || step.length() == 0) {
    QMessageBox::warning(this, "Just no",
                         "Укажите параметры системы координат.");
  } else if ((height_l.toDouble() == 0 &&
              height_l.contains(QRegularExpression("[^0]"))) ||
             (height_h.toDouble() == 0 &&
              height_h.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод y.");
  } else if ((width_l.toDouble() == 0 &&
              width_l.contains(QRegularExpression("[^0]"))) ||
             (width_h.toDouble() == 0 &&
              width_h.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод x.");
  } else if (step.toDouble() == 0 &&
             step.contains(QRegularExpression("[^0]"))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод шага.");
  } else if (height_l >= height_h) {
    QMessageBox::warning(this, "Just no", "Min height is more than Max.");
  } else if (width_l >= width_h) {
    QMessageBox::warning(this, "Just no", "Min width is more than Max.");
  } else if (step.toDouble() <= 0) {
    QMessageBox::warning(this, "Just no",
                         "Step must be positive number more than 0.");
  } else if (width_h.toDouble() >= 1000000 || height_h.toDouble() >= 1000000 ||
             width_l.toDouble() <= -1000000 ||
             height_l.toDouble() <= -1000000) {
    QMessageBox::warning(
        this, "Just no",
        "Height and width must be between 999999 and -999999.");
  } else {
    ui->graph->xAxis->setRange(width_l.toDouble(), width_h.toDouble());
    ui->graph->yAxis->setRange(height_l.toDouble(), height_h.toDouble());
    ui->graph->replot();
  }
}

void MainWindow::on_button_show_graph_clicked() {
  QString height_l = ui->start_y->text();
  QString height_h = ui->end_y->text();
  QString width_l = ui->start_x->text();
  QString width_h = ui->end_x->text();
  QString step = ui->step_width->text();
  QString string = ui->line_equasion->text();
  QString check = ui->line_equasion->text() + "     ";
  bool no_error = true;
  int length = 0;
  s21::calc_controller calc;
  double result = 0;
  std::string string_std;
  std::string *string_massive_std = NULL, *djicstra_massive_std = NULL;
  x.clear();
  y.clear();

  if (height_l.length() == 0 || height_h.length() == 0 ||
      width_l.length() == 0 || width_h.length() == 0 || step.length() == 0) {
    QMessageBox::warning(this, "Just no",
                         "Укажите параметры системы координат.");
  } else if ((height_l.toDouble() == 0 &&
              height_l.contains(QRegularExpression("[^0]"))) ||
             (height_h.toDouble() == 0 &&
              height_h.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод y.");
  } else if ((width_l.toDouble() == 0 &&
              width_l.contains(QRegularExpression("[^0]"))) ||
             (width_h.toDouble() == 0 &&
              width_h.contains(QRegularExpression("[^0]")))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод x.");
  } else if (step.toDouble() == 0 &&
             step.contains(QRegularExpression("[^0]"))) {
    QMessageBox::warning(this, "Just no", "Неверный ввод шага.");
  } else if (height_l >= height_h) {
    QMessageBox::warning(this, "Just no", "Min height is more than Max.");
  } else if (width_l >= width_h) {
    QMessageBox::warning(this, "Just no", "Min width is more than Max.");
  } else if (step.toDouble() <= 0) {
    QMessageBox::warning(this, "Just no",
                         "Step must be positive number more than 0.");
  } else if (width_h.toDouble() >= 1000000 || height_h.toDouble() >= 1000000 ||
             width_l.toDouble() <= -1000000 ||
             height_l.toDouble() <= -1000000) {
    QMessageBox::warning(
        this, "Just no",
        "Height and width must be between 999999 and -999999.");
  } else if (calc.check_equation_line(check.toStdString(), 0) != 0 &&
             calc.check_equation_line(check.toStdString(), 0) != 6) {
    QMessageBox::warning(this, "Just no", "Error in equasion.");
    x.clear();
    y.clear();
  } else if (fabs((height_h.toDouble() - height_l.toDouble()) /
                  step.toDouble()) > 100000) {
    QMessageBox::warning(this, "Just no", "Number of steps exeeds 100000.");
  } else if (string.toDouble() != 0 ||
             !(string.contains(QRegularExpression("[^0]")))) {
    //забыл зачем тут регулярка по логике там не должно быть "!" проверить потом
    for (double i = height_l.toDouble(); i <= height_h.toDouble();
         i += step.toDouble()) {
      x.push_back(i);
      y.push_back(string.toDouble());
    }
    ui->graph->clearGraphs();
    ui->graph->addGraph();
    ui->graph->graph(0)->addData(x, y);
    ui->graph->replot();
  } else {
    for (double i = height_l.toDouble();
         i <= height_h.toDouble() && no_error == true; i += step.toDouble()) {
      string = ui->line_equasion->text();
      x.push_back(i);
      QString valueAsString = "0";
      if (i < 0.000001 && i > -0.000001) {
        valueAsString = "0";
      } else {
        valueAsString = QString::number(i);
      }
      string.replace("x", valueAsString);
      string.replace(" ", "");
      string.replace("--", "++");
      string.replace("++", "+");
      string_std = calc.change_scientific_notation(string.toStdString());
      string_massive_std = calc.break_string(string_std, &no_error, &length);
      if (no_error == false) {
        QMessageBox::warning(this, "Just no", "Wrong equasion.");
      }
      if (no_error == true) {
        djicstra_massive_std =
            calc.string_to_djicstra(string_massive_std, length);
        result = calc.calculation(djicstra_massive_std, length);
      }
      y.push_back(result);
    }
    if (no_error == true) {
      ui->graph->clearGraphs();
      ui->graph->addGraph();
      ui->graph->graph(0)->addData(x, y);
      ui->graph->replot();
    }
  }
}

void MainWindow::on_button_clear_graph_clicked() {
  ui->graph->clearGraphs();
  ui->graph->replot();
}

void MainWindow::on_credit_calculator_clicked() {
  Credit credit_window;
  credit_window.setModal(true);
  credit_window.setWindowTitle("Credit calculator");
  credit_window.exec();
}

void MainWindow::on_deposit_calculator_clicked() {
  deposit deposit_window;
  deposit_window.setModal(true);
  deposit_window.setWindowTitle("Deposit calculator");
  deposit_window.exec();
}
