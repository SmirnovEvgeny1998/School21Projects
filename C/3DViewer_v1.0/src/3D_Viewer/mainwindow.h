#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define RED 0
#define GREEN 1
#define BLUE 2

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QTime>
#include <QWidget>

#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private slots:

  void slider_rotation();

  void slider_translation();

  void on_scaling_slider_valueChanged(int value);

  void radio_clicked();

  void set_defaults();

  void set_color();

  void on_load_obj_button_clicked();

  void on_save_settings_clicked();

  void on_load_settings_clicked();

  void on_line_width_slider_valueChanged(int value);

  void on_vertex_width_slider_valueChanged(int value);

  void on_save_in_jpeg_clicked();

  void on_save_in_bmp_clicked();

  void on_save_in_gif_clicked();

  void on_reset_position_released();

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QByteArray full_path_filename;

  double current_x_angle;

  double current_y_angle;

  double current_z_angle;

  double current_scale;

  double current_x_trans;

  double current_y_trans;

  double current_z_trans;

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
