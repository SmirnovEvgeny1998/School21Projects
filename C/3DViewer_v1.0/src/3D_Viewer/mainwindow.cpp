#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "QtWidgets/qfiledialog.h"
#include "gif.h"
#include "myopenglwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QList<QRadioButton *> radio_buttons = findChildren<QRadioButton *>();
  for (auto radio_button : radio_buttons) {
    connect(radio_button, &QRadioButton::clicked, this,
            &MainWindow::radio_clicked);
  }

  connect(ui->X_rotation_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_rotation);
  connect(ui->Y_rotation_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_rotation);
  connect(ui->Z_rotation_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_rotation);

  connect(ui->X_trans_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_translation);
  connect(ui->Y_trans_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_translation);
  connect(ui->Z_trans_slider, &QSlider::valueChanged, this,
          &MainWindow::slider_translation);

  QList<QSlider *> sliders = findChildren<QSlider *>();
  for (auto slider : sliders) {
    if (slider->objectName().contains("color")) {
      connect(slider, &QSlider::valueChanged, this, &MainWindow::set_color);
    }
  }
}

MainWindow::~MainWindow() {
  if (ui->oglwidget->obj) free_obj(ui->oglwidget->obj);
  delete ui;
}

void MainWindow::on_load_obj_button_clicked() {
  QString filename = QFileDialog::getOpenFileName(this, "Open a File", ".");
  QFileInfo fileinfo{filename};
  this->full_path_filename = filename.toLocal8Bit();
  ui->name_label->setText(fileinfo.fileName());
  if (!filename.isEmpty()) {
    if (ui->oglwidget->obj) free_obj(ui->oglwidget->obj);
    ui->oglwidget->obj = load_obj_info(full_path_filename.data());
  }
  if (ui->oglwidget->obj) {
    ui->oglwidget->get_max_coord_of_obj();
    this->set_defaults();
    ui->vertices_label->setText(
        QString::number(ui->oglwidget->obj->vert_number));
    ui->faces_label->setText(QString::number(ui->oglwidget->obj->faces_number));
  }
  ui->oglwidget->update();
}

void MainWindow::set_defaults() {
  double start_pos_Z = -1 - (ui->oglwidget->max_coord);
  motion_vertex(0, 0, start_pos_Z, ui->oglwidget->obj->vert_number,
                ui->oglwidget->obj->vert_arr);
  this->current_x_angle = 0.0f;
  this->current_y_angle = 0.0f;
  this->current_z_angle = 0.0f;
  this->current_scale = 1.0f;
  this->current_x_trans = 0.0f;
  this->current_y_trans = 0.0f;
  this->current_z_trans = start_pos_Z;

  ui->X_rotation_slider->setEnabled(true);
  ui->X_rotation_slider->setSliderPosition(0);
  ui->Y_rotation_slider->setEnabled(true);
  ui->Y_rotation_slider->setSliderPosition(0);
  ui->Z_rotation_slider->setEnabled(true);
  ui->Z_rotation_slider->setSliderPosition(0);

  ui->scaling_slider->setEnabled(true);
  ui->scaling_slider->setSliderPosition(1000);

  int max_trans_pos = (int)(500 * ui->oglwidget->max_coord);

  ui->X_trans_slider->setEnabled(true);
  ui->X_trans_slider->setMinimum(-max_trans_pos);
  ui->X_trans_slider->setMaximum(max_trans_pos);
  ui->X_trans_slider->setSliderPosition(0);
  ui->Y_trans_slider->setEnabled(true);
  ui->Y_trans_slider->setMinimum(-max_trans_pos);
  ui->Y_trans_slider->setMaximum(max_trans_pos);
  ui->Y_trans_slider->setSliderPosition(0);
  ui->Z_trans_slider->setEnabled(true);
  ui->Z_trans_slider->setMinimum(-max_trans_pos + (int)(start_pos_Z * 100));
  ui->Z_trans_slider->setMaximum(max_trans_pos + (int)(start_pos_Z * 100));
  ui->Z_trans_slider->setSliderPosition((int)(start_pos_Z * 100));
}

void MainWindow::on_reset_position_released() {
  if (ui->oglwidget->obj) {
    free_obj(ui->oglwidget->obj);
    ui->oglwidget->obj = load_obj_info(this->full_path_filename.data());
    this->set_defaults();
  }
  ui->oglwidget->update();
}

void MainWindow::radio_clicked() {
  QRadioButton *radio_button = qobject_cast<QRadioButton *>(sender());
  if (radio_button->objectName() == "parallel_proj") {
    ui->oglwidget->parallel_proj = true;
  } else if (radio_button->objectName() == "central_proj") {
    ui->oglwidget->parallel_proj = false;
  } else if (radio_button->objectName() == "not_stipple_line") {
    ui->oglwidget->stipple_line = false;
  } else if (radio_button->objectName() == "stipple_line") {
    ui->oglwidget->stipple_line = true;
  } else if (radio_button->objectName() == "circle_vert_radio") {
    ui->oglwidget->smooth_point = true;
    ui->oglwidget->enable_points = true;
  } else if (radio_button->objectName() == "square_vert_radio") {
    ui->oglwidget->smooth_point = false;
    ui->oglwidget->enable_points = true;
  } else if (radio_button->objectName() == "disable_vert_radio") {
    ui->oglwidget->enable_points = false;
  }
  ui->oglwidget->update();
}

void MainWindow::slider_rotation() {
  double rotation_x_angle =
      (double)ui->X_rotation_slider->value() / 100000 - (this->current_x_angle);
  double rotation_y_angle =
      (double)ui->Y_rotation_slider->value() / 100000 - (this->current_y_angle);
  double rotation_z_angle =
      (double)ui->Z_rotation_slider->value() / 100000 - (this->current_z_angle);
  this->current_x_angle = (double)ui->X_rotation_slider->value() / 100000;
  this->current_y_angle = (double)ui->Y_rotation_slider->value() / 100000;
  this->current_z_angle = (double)ui->Z_rotation_slider->value() / 100000;
  ui->x_angle->setText(QString::number((int)(current_x_angle * 180 / 3.14)) +
                       "°");
  ui->y_angle->setText(QString::number((int)(current_y_angle * 180 / 3.14)) +
                       "°");
  ui->z_angle->setText(QString::number((int)(current_z_angle * 180 / 3.14)) +
                       "°");
  if (ui->oglwidget->obj) {
    motion_vertex(-this->current_x_trans, -this->current_y_trans,
                  -this->current_z_trans, ui->oglwidget->obj->vert_number,
                  ui->oglwidget->obj->vert_arr);
    rotate(ui->oglwidget->obj->vert_arr, ui->oglwidget->obj->vert_number,
           rotation_x_angle, rotation_y_angle, rotation_z_angle);
    motion_vertex(this->current_x_trans, this->current_y_trans,
                  this->current_z_trans, ui->oglwidget->obj->vert_number,
                  ui->oglwidget->obj->vert_arr);
    ui->oglwidget->update();
  }
}

void MainWindow::slider_translation() {
  double x_trans_value =
      (double)ui->X_trans_slider->value() / 100 - this->current_x_trans;
  double y_trans_value =
      (double)ui->Y_trans_slider->value() / 100 - this->current_y_trans;
  double z_trans_value =
      (double)ui->Z_trans_slider->value() / 100 - this->current_z_trans;
  this->current_x_trans = (double)ui->X_trans_slider->value() / 100;
  this->current_y_trans = (double)ui->Y_trans_slider->value() / 100;
  this->current_z_trans = (double)ui->Z_trans_slider->value() / 100;
  if (ui->oglwidget->obj) {
    motion_vertex(x_trans_value, y_trans_value, z_trans_value,
                  ui->oglwidget->obj->vert_number,
                  ui->oglwidget->obj->vert_arr);
  }
  ui->oglwidget->update();
}

void MainWindow::on_scaling_slider_valueChanged(int value) {
  double scaling_value =
      ((double)ui->scaling_slider->value() / 1000) / this->current_scale;
  if (ui->oglwidget->obj) {
    motion_vertex(-this->current_x_trans, -this->current_y_trans,
                  -this->current_z_trans, ui->oglwidget->obj->vert_number,
                  ui->oglwidget->obj->vert_arr);
    scaling(ui->oglwidget->obj->vert_arr, ui->oglwidget->obj->vert_number,
            scaling_value);
    motion_vertex(this->current_x_trans, this->current_y_trans,
                  this->current_z_trans, ui->oglwidget->obj->vert_number,
                  ui->oglwidget->obj->vert_arr);
    ui->oglwidget->update();
  }
  this->current_scale = (double)ui->scaling_slider->value() / 1000;
  ui->scale->setText(QString::number(current_scale, 'f', 2));
}

void MainWindow::set_color() {
  ui->oglwidget->background_color[RED] =
      (double)ui->back_color_R->value() / 100;
  ui->oglwidget->background_color[GREEN] =
      (double)ui->back_color_G->value() / 100;
  ui->oglwidget->background_color[BLUE] =
      (double)ui->back_color_B->value() / 100;
  ui->oglwidget->line_color[RED] = (double)ui->line_color_R->value() / 100;
  ui->oglwidget->line_color[GREEN] = (double)ui->line_color_G->value() / 100;
  ui->oglwidget->line_color[BLUE] = (double)ui->line_color_B->value() / 100;
  ui->oglwidget->vert_color[RED] = (double)ui->vert_color_R->value() / 100;
  ui->oglwidget->vert_color[GREEN] = (double)ui->vert_color_G->value() / 100;
  ui->oglwidget->vert_color[BLUE] = (double)ui->vert_color_B->value() / 100;
  ui->oglwidget->update();
}

void MainWindow::on_line_width_slider_valueChanged(int value) {
  ui->oglwidget->line_width = value;
  ui->oglwidget->update();
}

void MainWindow::on_vertex_width_slider_valueChanged(int value) {
  ui->oglwidget->vertex_width = value;
  ui->oglwidget->update();
}

void MainWindow::on_save_settings_clicked() {
  QSettings *set =
      new QSettings(QSettings::IniFormat, QSettings::UserScope, "3D_viewer");
  set->setValue("pos_1", ui->back_color_R->value());
  set->setValue("pos_2", ui->back_color_G->value());
  set->setValue("pos_3", ui->back_color_B->value());
  set->setValue("pos_4", ui->line_width_slider->value());
  set->setValue("pos_5", ui->vertex_width_slider->value());
  set->setValue("pos_6", ui->line_color_R->value());
  set->setValue("pos_7", ui->line_color_G->value());
  set->setValue("pos_8", ui->line_color_B->value());
  set->setValue("pos_9", ui->vert_color_R->value());
  set->setValue("pos_10", ui->vert_color_G->value());
  set->setValue("pos_11", ui->vert_color_B->value());
  set->setValue("rad_1", ui->stipple_line->isChecked());
  set->setValue("rad_2", ui->not_stipple_line->isChecked());
  set->setValue("rad_3", ui->parallel_proj->isChecked());
  set->setValue("rad_4", ui->central_proj->isChecked());
  set->setValue("circle_vert", ui->circle_vert_radio->isChecked());
  set->setValue("square_vert", ui->square_vert_radio->isChecked());
  set->setValue("disable_vert", ui->disable_vert_radio->isChecked());
}

void MainWindow::on_load_settings_clicked() {
  QSettings *set =
      new QSettings(QSettings::IniFormat, QSettings::UserScope, "3D_viewer");
  if (set != nullptr) {
    ui->back_color_R->setValue(set->value("pos_1", "").toInt());
    ui->back_color_G->setValue(set->value("pos_2", "").toInt());
    ui->back_color_B->setValue(set->value("pos_3", "").toInt());
    ui->line_width_slider->setValue(set->value("pos_4", "").toInt());
    ui->vertex_width_slider->setValue(set->value("pos_5", "").toInt());
    ui->line_color_R->setValue(set->value("pos_6", "").toInt());
    ui->line_color_G->setValue(set->value("pos_7", "").toInt());
    ui->line_color_B->setValue(set->value("pos_8", "").toInt());
    ui->vert_color_R->setValue(set->value("pos_9", "").toInt());
    ui->vert_color_G->setValue(set->value("pos_10", "").toInt());
    ui->vert_color_B->setValue(set->value("pos_11", "").toInt());
    if (set->value("rad_1", "").toBool()) ui->stipple_line->click();
    if (set->value("rad_2", "").toBool()) ui->not_stipple_line->click();
    if (set->value("rad_3", "").toBool()) ui->parallel_proj->click();
    if (set->value("rad_4", "").toBool()) ui->central_proj->click();
    if (set->value("circle_vert", "").toBool()) ui->circle_vert_radio->click();
    if (set->value("square_vert", "").toBool()) ui->square_vert_radio->click();
    if (set->value("disable_vert", "").toBool())
      ui->disable_vert_radio->click();
  }
  ui->oglwidget->update();
}

void MainWindow::on_save_in_jpeg_clicked() {
  QImage image = ui->oglwidget->grabFramebuffer();
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save Image File"), QString(), tr("Images (*.jpeg)"));
  if (!fileName.isEmpty()) {
    image.save(fileName);
  }
}

void MainWindow::on_save_in_bmp_clicked() {
  QImage image = ui->oglwidget->grabFramebuffer();
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save Image File"), QString(), tr("Images (*.bmp)"));
  if (!fileName.isEmpty()) {
    image.save(fileName);
  }
}

void MainWindow::on_save_in_gif_clicked() {
  QString fileName = QFileDialog::getSaveFileName(
      this, tr("Save Image File"), QString(), tr("Images (*.gif)"));
  std::string cpp_filename = fileName.toStdString();
  const char *c_filename = cpp_filename.c_str();
  if (!fileName.isEmpty()) {
    std::array<QImage, 50> image_arr;
    for (int i = 0; i < 50; i++) {
      QTime dieTime = QTime::currentTime().addMSecs(100);
      image_arr[i] = ui->oglwidget->grabFramebuffer();
      while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    GifWriter writer = {};
    GifBegin(&writer, c_filename, image_arr[0].width(), image_arr[0].height(),
             10);
    for (int frame = 0; frame < 50; frame++) {
      GifWriteFrame(&writer, image_arr[frame].constBits(),
                    image_arr[frame].width(), image_arr[frame].height(), 10);
    }
    GifEnd(&writer);
  }
}
