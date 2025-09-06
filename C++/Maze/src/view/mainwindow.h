#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>
#include <set>

#include "../controller/MazeController.h"
#include "../controller/controller.h"
#include "QtWidgets/qfiledialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, s21::Controller *cave_ctrl = nullptr,
             MazeController *maze_ctrl = nullptr);
  ~MainWindow();

 private slots:
  void mousePressEvent(QMouseEvent *event) override;
  void on_tabWidget_currentChanged(int index);

 private:
  bool maze_mode_;
  bool cave_mode_;
  s21::Controller *cave_ctrl_;
  MazeController *maze_ctrl_;
  Ui::MainWindow *ui;
  void onLoadButtonClicked();
  void generateMaze();
  void solveMaze();
  void onJumpButtonClicked();
  void onGoButtonClicked();
  void onExportButtonClicked();
  void drawCave();
  void drawMaze();
  void drawPath(std::list<std::pair<int, int>> path);
  std::set<std::pair<int, int>> start_finish_positions_;
  bool go_is_enabled_;
  bool cave_is_loaded_;
};
#endif  // MAINWINDOW_H
