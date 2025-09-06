#include <locale.h>

#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextEdit>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_ALL, "en_US.utf8");
  MainWindow w;
  w.show();
  return a.exec();
}
