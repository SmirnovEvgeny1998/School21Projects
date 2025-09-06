#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "QFileInfo"
#include "QThread"
#include "QTimer"
#include "qpainter.h"

MainWindow::MainWindow(QWidget *parent, s21::Controller *cave_ctrl,
                       MazeController *maze_ctrl)
    : QMainWindow(parent),
      cave_ctrl_(cave_ctrl),
      maze_ctrl_(maze_ctrl),
      ui(new Ui::MainWindow)

{
  ui->setupUi(this);

  connect(ui->load_cave_button, &QPushButton::released, this,
          &MainWindow::onLoadButtonClicked);
  connect(ui->export_button, &QPushButton::released, this,
          &MainWindow::onExportButtonClicked);
  connect(ui->load_maze_button, &QPushButton::released, this,
          &MainWindow::onLoadButtonClicked);
  connect(ui->go_button, &QPushButton::released, this,
          &MainWindow::onGoButtonClicked);
  connect(ui->generate_button, &QPushButton::released, this,
          &MainWindow::generateMaze);
  connect(ui->solve_button, &QPushButton::released, this,
          &MainWindow::solveMaze);
  connect(ui->jump_button, &QPushButton::released, this,
          &MainWindow::onJumpButtonClicked);
  maze_mode_ = true;
  cave_mode_ = false;
  cave_is_loaded_ = false;
  go_is_enabled_ = false;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onLoadButtonClicked() {
  QString filename = QFileDialog::getOpenFileName(
      this, "Open a File", QDir::currentPath(), tr("Text Files (*.txt)"));
  if (filename != "") {
    try {
      if (sender()->objectName() == "load_maze_button") {
        maze_ctrl_->LoadMaze(filename.toStdString());
        start_finish_positions_.clear();
        drawMaze();
      } else {
        cave_ctrl_->LoadFromFile(filename.toStdString());
        cave_is_loaded_ = true;
        drawCave();
      }
    } catch (std::invalid_argument &e) {
      QMessageBox msgWarning;
      msgWarning.setText(QString(e.what()));
      msgWarning.setIcon(QMessageBox::Warning);
      msgWarning.setWindowTitle("Caution");
      msgWarning.exec();
    }
  }
}

void MainWindow::onExportButtonClicked() {
  QString filename = QFileDialog::getSaveFileName(
      this, tr("Save Maze"), QString(), tr("Text (*.txt)"));
  if (!filename.isEmpty()) {
    try {
      maze_ctrl_->ExportMaze(filename.toStdString());
    } catch (std::invalid_argument &e) {
      QMessageBox msgWarning;
      msgWarning.setText(QString(e.what()));
      msgWarning.setIcon(QMessageBox::Warning);
      msgWarning.setWindowTitle("Caution");
      msgWarning.exec();
    }
  }
}

void MainWindow::generateMaze() {
  maze_ctrl_->GenerateMaze(ui->height_box->text().toInt(),
                           ui->width_box->text().toInt());
  start_finish_positions_.clear();
  drawMaze();
}

void MainWindow::solveMaze() {
  if (start_finish_positions_.size() == 2) {
    auto it = start_finish_positions_.begin();
    int start_x = it->first;
    int start_y = it->second;
    it++;
    int finish_x = it->first;
    int finish_y = it->second;
    drawPath(maze_ctrl_->SolveMaze(start_x, start_y, finish_x, finish_y));
  } else {
    QMessageBox msgWarning;
    msgWarning.setText(QString("Set start and finish positions"));
    msgWarning.setIcon(QMessageBox::Warning);
    msgWarning.setWindowTitle("Caution");
    msgWarning.exec();
  }
}

void MainWindow::onGoButtonClicked() {
  cave_ctrl_->setBurthLimit(ui->line_edit_birth->text().toInt());
  cave_ctrl_->setDeathLimit(ui->line_edit_death->text().toInt());
  go_is_enabled_ = !go_is_enabled_;
  if (!go_is_enabled_) {
    ui->go_button->setText("Go");
  } else {
    ui->go_button->setText("Stop");
  }
  while (go_is_enabled_ && cave_is_loaded_) {
    int period = ui->freq_box->text().toInt();
    if (period < 100) period = 100;
    QTime dieTime = QTime::currentTime().addMSecs(period);
    cave_ctrl_->updateCave();
    drawCave();
    while (QTime::currentTime() < dieTime)
      QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
  }
}

void MainWindow::onJumpButtonClicked() {
  if (cave_is_loaded_) {
    cave_ctrl_->setBurthLimit(ui->line_edit_birth->text().toInt());
    cave_ctrl_->setDeathLimit(ui->line_edit_death->text().toInt());
    for (int i = 0; i < ui->jump_spinBox->value(); i++) {
      cave_ctrl_->updateCave();
    }
    drawCave();
  }
}

void MainWindow::drawCave() {
  std::vector f = cave_ctrl_->getField();
  QPixmap pixmap(f.size(), f[0].size());
  pixmap.fill(Qt::white);

  QPainter painter(&pixmap);
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(QPen(QColor("transparent")));

  for (int i = 0; i < f.size(); i++)
    for (int j = 0; j < f[0].size(); j++) {
      if (f[j][i]) painter.drawRect(i, j, 1, 1);
    }
  QPixmap pixmapScaled = pixmap.scaled(500, 500);
  ui->cave_label->setPixmap(pixmapScaled);
  ui->cave_label->update();
}

void MainWindow::drawMaze() {
  MazeController::MazeInfo maze_info = maze_ctrl_->GetMazeInfo();
  double cell_height = 500.0 / maze_info.maze_height;
  double cell_width = 500.0 / maze_info.maze_width;
  QPixmap pixmap(500, 500);
  pixmap.fill(Qt::white);
  QPainter painter(&pixmap);
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(QPen(Qt::black));

  for (int i = 0; i < maze_info.maze_height; i++) {
    for (int j = 0; j < maze_info.maze_width; j++) {
      if (maze_info.RWMatrix[i][j]) {
        painter.drawLine(QPointF((j + 1) * cell_width, i * cell_height),
                         QPointF((j + 1) * cell_width, (i + 1) * cell_height));
      }
      if (maze_info.FMatrix[i][j]) {
        painter.drawLine(QPointF(j * cell_width, (i + 1) * cell_height),
                         QPointF((j + 1) * cell_width, (i + 1) * cell_height));
      }
    }
  }
  painter.setBrush(QBrush(Qt::red));
  painter.setPen(QPen(Qt::red));

  for (auto it = start_finish_positions_.begin();
       it != start_finish_positions_.end(); it++) {
    double x = (double)(*it).first;
    double y = (double)(*it).second;
    painter.drawRect(QRectF(QPointF(x * cell_width, y * cell_height),
                            QSizeF(cell_width, cell_height)));
  }
  ui->maze_label->setPixmap(pixmap);
  ui->maze_label->update();
}

void MainWindow::drawPath(std::list<std::pair<int, int>> path) {
  MazeController::MazeInfo maze_info = maze_ctrl_->GetMazeInfo();
  double cell_height = 500.0 / maze_info.maze_height;
  double cell_width = 500.0 / maze_info.maze_width;

  QPixmap pixmap(500, 500);
  QPainter painter(&pixmap);
  painter.setBrush(QBrush(Qt::red));
  painter.setPen(QPen(Qt::red));

  std::list<std::pair<int, int>>::iterator tmp;
  for (auto a = path.begin(), tmp = path.begin(); a != path.end(); a++) {
    double x = (double)(*a).second;
    double y = (double)(*a).first;
    double x_tmp = (double)(*tmp).second;
    double y_tmp = (double)(*tmp).first;
    painter.drawLine(
        QPointF((x_tmp + 0.5) * cell_width, (y_tmp + 0.5) * cell_height),
        QPointF((x + 0.5) * cell_width, (y + 0.5) * cell_height));
    tmp = a;
  }
  ui->maze_label->setPixmap(pixmap);
  ui->maze_label->update();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  if (maze_mode_) {
    MazeController::MazeInfo maze_info = maze_ctrl_->GetMazeInfo();
    double cell_height = 500.0 / maze_info.maze_height;
    double cell_width = 500.0 / maze_info.maze_width;
    QPoint mouse_pos = event->pos();
    std::pair<int, int> new_point(
        (int)((mouse_pos.x() - ui->maze_label->x()) / cell_width),
        (int)((mouse_pos.y() - ui->maze_label->y() - 24.0) / cell_height));

    qDebug() << new_point.first << new_point.second;
    if (new_point.first < maze_info.maze_width &&
        new_point.second < maze_info.maze_height) {
      if (start_finish_positions_.find(new_point) !=
          start_finish_positions_.end()) {
        start_finish_positions_.erase(new_point);
      } else {
        if (start_finish_positions_.size() < 2) {
          start_finish_positions_.insert(new_point);
        }
      }
    }
    drawMaze();
  }

  if (cave_mode_ && cave_is_loaded_) {
    std::vector f = cave_ctrl_->getField();
    double cell_width = 500.0 / f[0].size();
    double cell_height = 500.0 / f.size();
    QPoint mouse_pos = event->pos();
    std::pair<int, int> new_point(
        (int)((mouse_pos.x() - ui->maze_label->x()) / cell_width),
        (int)((mouse_pos.y() - ui->maze_label->y() - 24.0) / cell_height));
    if (new_point.first < f.size() && new_point.second < f[0].size()) {
      if (f[new_point.second][new_point.first] == 1) {
        cave_ctrl_->setFieldValue(new_point.second, new_point.first, 0);
      } else {
        cave_ctrl_->setFieldValue(new_point.second, new_point.first, 1);
      }
      drawCave();
    }
  }
}

void MainWindow::on_tabWidget_currentChanged(int index) {
  if (index == 0) {
    maze_mode_ = true;
    cave_mode_ = false;
  } else {
    maze_mode_ = false;
    cave_mode_ = true;
  }
}
