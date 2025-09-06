#include <QApplication>

#include "../controller/MazeController.h"
#include "../controller/controller.h"
#include "../model/MazeModel.h"
#include "../model/cave.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::cave cave1;
  Maze m(50, 50);
  MazeController maze_ctrl(&m);
  s21::Controller cave_ctrl(&cave1);
  MainWindow w(nullptr, &cave_ctrl, &maze_ctrl);
  w.show();
  return a.exec();
}
