#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

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

extern "C" {
#include "s21_smart_calc.c"
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);
    ui->month_percents->setReadOnly(true);
    ui->alltime_percents->setReadOnly(true);
    ui->full_summ->setReadOnly(true);
    ui->widget->xAxis->setRange(-3, 3);
    ui->widget->yAxis->setRange(-1, 1);
    ui->height_l->setText("-1");
    ui->height_h->setText("1");
    ui->width_l->setText("-3");
    ui->width_h->setText("3");
    ui->step->setText("0.01");
    ui->hidden_month->hide();
    ui->hidden_year->hide();
    ui->hidden_summ->hide();
    ui->hidden_month_2->hide();
    ui->hidden_year_2->hide();
    ui->hidden_summ_2->hide();
    ui->pushButton_29->hide();
    ui->pushButton_36->hide();
    ui->deposit_end_summ->setReadOnly(true);
    ui->deposit_tax->setReadOnly(true);
    ui->deposit_percents_dohod->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_pushButton_clicked()
{
    char* text = "1+2";
    char fext[500] = "";
    QString dext = "q";
    s21_string_to_djicstra(text, fext);
    double result = s21_calculation(fext);
    QString valueAsString = QString::number(result);
    ui->lineEdit->setText(valueAsString);
}*/


void MainWindow::on_pushButton_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "1";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "2";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "3";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "4";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "5";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "6";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "7";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "8";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "9";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "0";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "(";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += ")";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "+";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "-";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "*";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "/";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_17_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "^";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_18_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 253) {
        string += "mod";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_19_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 253) {
        string += "cos";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 253) {
        string += "sin";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_21_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 253) {
        string += "tan";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_22_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 252) {
        string += "acos";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 252) {
        string += "asin";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_24_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 252) {
        string += "atan";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_25_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 252) {
        string += "sqrt";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_26_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 254) {
        string += "ln";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_27_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 253) {
        string += "log";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_28_clicked()
{
    QString string = ui->lineEdit->text();
    QByteArray ba = string.toLocal8Bit();
    char *c_str2 = ba.data();
    char fext[500] = "";
    if (strlen(c_str2) == 0) {
        QMessageBox::warning(this, "Just no", "Пустое уравнение.");
    } else if(s21_check_if_only_znaks_and_not_pm_in_the_beginning(c_str2) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи уравнения 1.");
    } else if(s21_check_points(c_str2) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи точки.");
    } else if (s21_error_in_brackets(c_str2) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи скобок.");
    } else if(s21_correctness(c_str2) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи уравнения 2.");
    } else if(s21_only_number(c_str2) == 1) {
        ui->lineEdit->setText(string);
    } else if (strchr(c_str2, 'x') != NULL) {
        QMessageBox::warning(this, "Just no", "You cant compute x function, use graph instead man...");
    } else if(s21_check_bracket_after_sin(c_str2) == 1) {
        QMessageBox::warning(this, "Just no", "Uravnenie must follow sin(x) form.");
    } else {
        s21_string_to_djicstra(c_str2, fext);
        double result = s21_calculation(fext);
        QString valueAsString = QString::number(result);
        ui->lineEdit->setText(valueAsString);
    }
}


void MainWindow::on_pushButton_29_clicked()
{
    QString s = ui->lineEdit->text();
    if(!s.isEmpty()) {
        s.resize(s.size() - 1);
    }
    ui->lineEdit->setText(s);
}


void MainWindow::on_pushButton_30_clicked()
{
    QString s = ui->lineEdit->text();
    if(!s.isEmpty()) {
        s.resize(0);
    }
    ui->lineEdit->setText(s);
}


void MainWindow::on_pushButton_31_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += ".";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long");
    }
}


void MainWindow::on_pushButton_32_clicked()
{
    //
    int error = 0;
    QString height_l = ui->height_l->text();
    QString height_h = ui->height_h->text();
    QString width_l = ui->width_l->text();
    QString width_h = ui->width_h->text();
    QString step = ui->step->text();

    QByteArray b_height_l = height_l.toLocal8Bit();
    char *c_height_l = b_height_l.data();
    error = s21_check_step_width_heigth(c_height_l);

    QByteArray b_height_h = height_h.toLocal8Bit();
    char *c_height_h = b_height_h.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_height_h);
    }

    QByteArray b_width_h = width_h.toLocal8Bit();
    char *c_width_h = b_width_h.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_width_h);
    }

    QByteArray b_width_l = width_l.toLocal8Bit();
    char *c_width_l = b_width_l.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_width_l);
    }

    QByteArray b_step = step.toLocal8Bit();
    char *c_step = b_step.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_step);
    }
    //
    x.clear();
    y.clear();
    //char result[500] = {'\0'};
    QString string = ui->lineEdit->text();
    double x_cord = 0, xStep = 0;
    h = 0.01;
    QString sBegin_string = ui->width_l->text();
    QString sEnd_string = ui->width_h->text();
    QString sStep = ui->step->text();
    xBegin = sBegin_string.toDouble();
    xEnd = sEnd_string.toDouble();
    xStep = sStep.toDouble();
    //для проверки
    QByteArray error_s = string.toLocal8Bit();
    char *error_str_0 = error_s.data();
    if (error == 1) {
        QMessageBox::warning(this, "Just no", "Wrong number format.");
    } else if(width_l.toDouble() >= width_h.toDouble()) {
        QMessageBox::warning(this, "Just no", "Min width is more than Max.");
    } else if(height_l.toDouble() >= height_h.toDouble()) {
        QMessageBox::warning(this, "Just no", "Min height is more than Max.");
    } else if (strlen(error_str_0) == 0) {
        QMessageBox::warning(this, "Just no", "Пустое уравнение.");
    } else if(s21_check_if_only_znaks_and_not_pm_in_the_beginning(error_str_0) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи уравнения 1.");
    } else if(s21_check_points(error_str_0) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи точки.");
    } else if (s21_error_in_brackets(error_str_0) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи скобок.");
    } else if(s21_correctness(error_str_0) == 1) {
        QMessageBox::warning(this, "Just no", "Ошибка в записи уравнения 2.");
    } else if(s21_check_bracket_after_sin(error_str_0) == 1) {
        QMessageBox::warning(this, "Just no", "Uravnenie must follow sin(x) form.");
    } else if(s21_only_number(error_str_0) == 1) {
        h = xStep;
        if (fabs((xBegin - xEnd)/ h) > 100000) {
            QMessageBox::warning(this, "Just no", "Number of steps exeeds 10000.");
        } else {
            for (x_cord = xBegin; x_cord <= xEnd; x_cord += h) {
                x.push_back(x_cord);
                y.push_back(s21_calculation_one_number(error_str_0));
            }
            ui->widget->addGraph();
            ui->widget->graph(0)->addData(x,y);
            ui->widget->replot();
        }
    } else {
        h = xStep;
        if (fabs((xBegin - xEnd)/ h) > 100000) {
            QMessageBox::warning(this, "Just no", "Number of steps exeeds 10000.");
        } else {
            for (x_cord = xBegin; x_cord <= xEnd; x_cord += h) {
                x.push_back(x_cord);
                QString valueAsString = "0";
                if (x_cord < 0.01 && x_cord > -0.01) {
                    valueAsString = "0";
                } else {
                    valueAsString = QString::number(x_cord);
                }

                QByteArray ba = string.toLocal8Bit();
                char *c_str_0 = ba.data();
                char c_str2[500] = {'\0'};
                strcpy(c_str2, c_str_0);
                QByteArray ba_2 = valueAsString.toLocal8Bit();
                char *c_str2_2 = ba_2.data();
                y.push_back(s21_calculate_x(c_str2 ,c_str2_2));
            }
            ui->widget->clearGraphs();
            ui->widget->addGraph();
            ui->widget->graph(0)->addData(x,y);
            ui->widget->replot();
        }
    }
}


void MainWindow::on_pushButton_33_clicked()
{
    ui->widget->clearGraphs();
    ui->widget->replot();
}


void MainWindow::on_pushButton_34_clicked()
{
    QString string = ui->lineEdit->text();
    if (string.length() <= 255) {
        string += "x";
        ui->lineEdit->setText(string);
    } else {
        QMessageBox::warning(this, "Just no", "Math is too long.");
    }
}

void MainWindow::on_pushButton_35_clicked()
{
    int error = 0;
    QString height_l = ui->height_l->text();
    QString height_h = ui->height_h->text();
    QString width_l = ui->width_l->text();
    QString width_h = ui->width_h->text();
    QString step = ui->step->text();

    QByteArray b_height_l = height_l.toLocal8Bit();
    char *c_height_l = b_height_l.data();
    error = s21_check_step_width_heigth(c_height_l);

    QByteArray b_height_h = height_h.toLocal8Bit();
    char *c_height_h = b_height_h.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_height_h);
    }

    QByteArray b_width_h = width_h.toLocal8Bit();
    char *c_width_h = b_width_h.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_width_h);
    }

    QByteArray b_width_l = width_l.toLocal8Bit();
    char *c_width_l = b_width_l.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_width_l);
    }

    QByteArray b_step = step.toLocal8Bit();
    char *c_step = b_step.data();
    if (error == 0) {
        error = s21_check_step_width_heigth(c_step);
    }
    if (error == 1) {
        QMessageBox::warning(this, "Just no", "Wrong number format.");
    } else if(width_l.toDouble() >= width_h.toDouble()) {
        QMessageBox::warning(this, "Just no", "Min width is more than Max.");
    } else if(height_l.toDouble() >= height_h.toDouble()) {
        QMessageBox::warning(this, "Just no", "Min height is more than Max.");
    } else if(step.toDouble() <= 0) {
        QMessageBox::warning(this, "Just no", "Step must be positive number more than 0.");
    } else if(width_h.toDouble() >= 1000000 || height_h.toDouble() >= 1000000 || width_l.toDouble() <= -1000000 || height_l.toDouble() <= -1000000) {
        QMessageBox::warning(this, "Just no", "Height and width must be between 999999 and -999999.");
    } else {
        ui->widget->xAxis->setRange(width_l.toDouble(), width_h.toDouble());
        ui->widget->yAxis->setRange(height_l.toDouble(), height_h.toDouble());
    }
}


void MainWindow::on_pushButton_36_clicked()
{
    credit_window = new Credit(this);
    credit_window->show();
}


void MainWindow::on_pushButton_37_clicked()
{
    int annuitent = 0, differential = 0;
    double monthly_payment = 0, overpayment = 0, full_summ = 0;
    QString montly_payment_str, overpayment_str, full_summ_str;
    QString amount_str = ui->amount->text();
    QString lengrh_str = ui->length->text();
    QString percent_str = ui->percent->text();
    double amount = amount_str.toDouble();
    int lengrh = lengrh_str.toInt();
    double percent = percent_str.toDouble();

    QByteArray b_amount = amount_str.toLocal8Bit();
    char *c_amount = b_amount.data();
    QByteArray b_lengrh = lengrh_str.toLocal8Bit();
    char *c_lengrh = b_lengrh.data();
    QByteArray b_percent = percent_str.toLocal8Bit();
    char *c_percent = b_percent.data();

    if (ui->annuitent->isChecked()) {
        annuitent = 1;
        differential = 0;
    } else if (ui->differential->isChecked()) {
        annuitent = 0;
        differential = 1;
    }
    if (amount_str.length() == 0 || lengrh_str.length() == 0 || percent_str.length() == 0) {
        QMessageBox::warning(this, "Just no", "Fulfill the lines.");
    } else if (s21_check_if_only_numbers(c_amount, 2) == 1 || s21_check_if_only_numbers(c_lengrh, 1) == 1 || s21_check_if_only_numbers(c_percent, 2) == 1) {
        QMessageBox::warning(this, "Just no", "Wrong characters.");
    } else if (lengrh > 600 || lengrh == 0) {
        QMessageBox::warning(this, "Just no", "No more than 50 years of credit and at least 1 month.");
    } else if (percent <= 0) {
        QMessageBox::warning(this, "Just no", "Percent must be positive number more than 0.");
    } else if (annuitent == 1) {
        monthly_payment = s21_bank_annuitent_montly_payment(amount, lengrh, percent);
        montly_payment_str = QString::number(monthly_payment, 'f', 2);
        ui->month_percents->setText(montly_payment_str);

        overpayment = s21_bank_annuitent_overpayment(amount, lengrh, percent);
        overpayment_str = QString::number(overpayment, 'f', 2);
        ui->alltime_percents->setText(overpayment_str);

        full_summ = s21_bank_annuitent_all_payment(amount, lengrh, percent);
        full_summ_str = QString::number(full_summ, 'f', 2);

        ui->full_summ->setText(full_summ_str);
    } else if (differential == 1) {
        monthly_payment = s21_bank_differential_montly_payment_first(amount, lengrh, percent);
        montly_payment_str = QString::number(monthly_payment, 'f', 2);
        montly_payment_str += " - ";
        monthly_payment = s21_bank_differential_montly_payment_last(amount, lengrh, percent);
        montly_payment_str += QString::number(monthly_payment, 'f', 2);
        ui->month_percents->setText(montly_payment_str);

        overpayment = s21_bank_differential_overpayment(amount, lengrh, percent);
        overpayment_str = QString::number(overpayment, 'f', 2);
        ui->alltime_percents->setText(overpayment_str);

        full_summ = s21_bank_differential_all_payment(amount, lengrh, percent);
        full_summ_str = QString::number(full_summ, 'f', 2);
        ui->full_summ->setText(full_summ_str);
    } else {
        QMessageBox::warning(this, "Just no", "Choose type.");
    }
}


void MainWindow::on_pushButton_38_clicked()
{
    double percents = 0, tax = 0, end_summ = 0;
    int capitalization = 0, deposit_periodisity = 0, repelishment_counter = 0, widhrawl_counter = 0;
    s21_repelishments rep[50] = {0};
    s21_widrawls wid[50] = {0};
    QString deposit_summ_str = ui->deposit_summ->text();
    QString deposit_length_str = ui->deposit_length->text();
    QString deposit_percent_str = ui->deposit_percent->text();
    QString stavka_CB_str = ui->stavka_CB->text();
    double deposit_summ = deposit_summ_str.toDouble();
    int deposit_length = deposit_length_str.toInt();
    double deposit_percent = deposit_percent_str.toDouble();
    double stavka_CB = stavka_CB_str.toDouble();

    QByteArray b_summ = deposit_summ_str.toLocal8Bit();
    char *c_summ = b_summ.data();
    QByteArray b_length = deposit_length_str.toLocal8Bit();
    char *c_length = b_length.data();
    QByteArray b_percent = deposit_percent_str.toLocal8Bit();
    char *c_percent = b_percent.data();
    QByteArray b_stavka_CB = stavka_CB_str.toLocal8Bit();
    char *c_stavka_CB = b_stavka_CB.data();

    deposit_periodisity = ui->deposit_periodicity->currentIndex();
    if (ui->deposit_capitalization->isChecked()) {
        capitalization = 1;
    } else {
        capitalization = 0;
    }
    repelishment_counter = ui->comboBox_3->count();
    widhrawl_counter = ui->comboBox_6->count();
    for (int i = 0; i < repelishment_counter; i++) {
        rep[i].month = ui->hidden_month->itemText(i).toInt();
        rep[i].year = ui->hidden_year->itemText(i).toInt();
        rep[i].summ = ui->hidden_summ->itemText(i).toDouble();
    }
    for (int i = 0; i < widhrawl_counter; i++) {
        wid[i].month = ui->hidden_month_2->itemText(i).toInt();
        wid[i].year = ui->hidden_year_2->itemText(i).toInt();
        wid[i].summ = ui->hidden_summ_2->itemText(i).toDouble();
    }
    if (repelishment_counter == 0) {
        rep[0].month = 0;
        rep[0].year = 0;
        rep[0].summ = 0;
        rep[0].last = 1;
    } else {
        rep[repelishment_counter-1].last = 1;
    }
    if (widhrawl_counter == 0) {
        wid[0].month = 0;
        wid[0].year = 0;
        wid[0].summ = 0;
        wid[0].last = 1;
    } else {
        wid[widhrawl_counter-1].last = 1;
    }
    if (deposit_summ_str.length() == 0 || deposit_percent_str.length() == 0 || deposit_length_str.length() == 0 || stavka_CB_str.length() == 0) {
        QMessageBox::warning(this, "Just no", "Fulfill the lines.");
    } else if(s21_check_if_only_numbers(c_summ, 2) == 1 || s21_check_if_only_numbers(c_length, 1) == 1 || s21_check_if_only_numbers(c_percent, 2) == 1 || s21_check_if_only_numbers(c_stavka_CB, 2) == 1) {
        QMessageBox::warning(this, "Just no", "Wrong characters.");
    } else if(deposit_length > 600 || deposit_length <= 0) {
        QMessageBox::warning(this, "Just no", "No more than 50 years of deposit and at least 1 month.");
    } else if(stavka_CB <= 0 || deposit_percent <= 0) {
        QMessageBox::warning(this, "Just no", "Percents and CB must be positive numbers more than 0.");
    } else {
        percents = s21_deposit_profitability_complex(0, deposit_summ, deposit_length, deposit_percent, 13, deposit_periodisity, capitalization, rep, wid, stavka_CB);
        tax = s21_deposit_profitability_complex(1, deposit_summ, deposit_length, deposit_percent, 13, deposit_periodisity, capitalization, rep, wid, stavka_CB);
        end_summ = s21_deposit_profitability_complex(2, deposit_summ, deposit_length, deposit_percent, 13, deposit_periodisity, capitalization, rep, wid, stavka_CB);
        if (percents < 0 || tax < 0 || end_summ < 0) {
            QMessageBox::warning(this, "Just no", "Widhrawl amount is bigger than deposit summ.");
        } else {
            ui->deposit_percents_dohod->setText(QString::number(percents, 'f', 2));
            ui->deposit_tax->setText(QString::number(tax, 'f', 2));
            ui->deposit_end_summ->setText(QString::number(end_summ, 'f', 2));
        }
    }
}


void MainWindow::on_popolnenie_clicked()
{
    int counter = ui->comboBox_3->count();
    QString add_summ_data = ui->deposit_periodisity_2->text();
    QByteArray b_add_summ = add_summ_data.toLocal8Bit();
    char *c_add_summ = b_add_summ.data();
    if (ui->deposit_periodisity_2->text().length() == 0) {
        QMessageBox::warning(this, "Just no", "Fulfill the amount.");
    } else if (s21_check_if_only_numbers(c_add_summ, 2) == 1) {
        QMessageBox::warning(this, "Just no", "Wrong characters.");
    } else if(counter >= 10) {
        QMessageBox::warning(this, "Just no", "No more than 10 repelishments.");
    } else {
        add_summ_data = ui->comboBox->currentText();
        ui->hidden_month->addItem(ui->comboBox->currentText());
        add_summ_data += "M - ";
        add_summ_data += ui->comboBox_2->currentText();
        ui->hidden_year->addItem(ui->comboBox_2->currentText());
        add_summ_data += "Y - ";
        add_summ_data += ui->deposit_periodisity_2->text();
        ui->hidden_summ->addItem(ui->deposit_periodisity_2->text());
        ui->comboBox_3->addItem(add_summ_data);
    }
}


void MainWindow::on_pushButton_39_clicked()
{
    int index = ui->comboBox_3->currentIndex();
    ui->comboBox_3->removeItem(index);
    ui->hidden_month->removeItem(index);
    ui->hidden_year->removeItem(index);
    ui->hidden_summ->removeItem(index);
}


void MainWindow::on_snyatie_clicked()
{
    int counter = ui->comboBox_6->count();
    QString remove_summ_data = ui->deposit_periodisity_3->text();
    QByteArray b_summ = remove_summ_data.toLocal8Bit();
    char *c_summ = b_summ.data();
    if (ui->deposit_periodisity_3->text().length() == 0) {
        QMessageBox::warning(this, "Just no", "Fulfill the amount.");
    } else if (s21_check_if_only_numbers(c_summ, 2) == 1) {
        QMessageBox::warning(this, "Just no", "Wrong characters.");
    } else if (counter >= 10) {
        QMessageBox::warning(this, "Just no", "No more than 10 widhrawls.");
    } else {
        remove_summ_data = ui->comboBox_4->currentText();
        ui->hidden_month_2->addItem(ui->comboBox_4->currentText());
        remove_summ_data += "M - ";
        remove_summ_data += ui->comboBox_5->currentText();
        ui->hidden_year_2->addItem(ui->comboBox_5->currentText());
        remove_summ_data += "Y - ";
        remove_summ_data += ui->deposit_periodisity_3->text();
        ui->hidden_summ_2->addItem(ui->deposit_periodisity_3->text());
        ui->comboBox_6->addItem(remove_summ_data);
    }
}


void MainWindow::on_pushButton_40_clicked()
{
    int index = ui->comboBox_6->currentIndex();
    printf("%d\n", index);
    ui->comboBox_6->removeItem(index);
    ui->hidden_month_2->removeItem(index);
    ui->hidden_year_2->removeItem(index);
    ui->hidden_summ_2->removeItem(index);
}

