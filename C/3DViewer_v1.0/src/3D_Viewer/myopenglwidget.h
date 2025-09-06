#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "../3D_Viewer_core.h"

class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  MyOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

  Obj *obj = nullptr;

  bool parallel_proj = false;

  bool stipple_line = false;

  bool enable_points = true;

  bool smooth_point = true;

  double max_coord = 0;

  double background_color[3] = {0, 0, 0};

  double line_color[3] = {1.0, 1.0, 1.0};

  double vert_color[3] = {1.0, 1.0, 1.0};

  int line_width = 1;

  int vertex_width = 1;

  void get_max_coord_of_obj() {
    max_coord = find_max_coord_of_vert(obj->vert_arr, obj->vert_number);
  }

 protected:
  void initializeGL() override {
    initializeOpenGLFunctions();
    glClearColor(background_color[0], background_color[1], background_color[2],
                 0);
    glEnable(GL_DEPTH_TEST);
  }

  void resizeGL(int width = 580, int height = 362) override {
    width *= this->devicePixelRatio();
    height *= this->devicePixelRatio();
    double zNear = 0.99f;

    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (parallel_proj) {
      double height_o = max_coord * 1.5f;
      double width_o = height_o * this->width() / this->height();
      glOrtho(-width_o, width_o, -height_o, height_o, -0.5f, max_coord * 5);
    } else {
      double height_f = zNear;
      double width_f = height_f * this->width() / this->height();
      glFrustum(-width_f, width_f, -height_f, height_f, zNear, max_coord * 10);
    }
  }

  void paintGL() override {
    glClearColor(background_color[0], background_color[1], background_color[2],
                 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (obj) {
      resizeGL();

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      glVertexPointer(3, GL_DOUBLE, 0, (double *)obj->vert_arr);
      glEnableClientState(GL_VERTEX_ARRAY);

      if (stipple_line) {
        glLineStipple(1, 0x00FF);
        glEnable(GL_LINE_STIPPLE);
      } else {
        glDisable(GL_LINE_STIPPLE);
      }

      if (smooth_point) {
        glEnable(GL_POINT_SMOOTH);
      } else {
        glDisable(GL_POINT_SMOOTH);
      }

      for (int i = 0; i < obj->faces_number; i++) {
        int face_len = obj->face_arr[i].size;
        unsigned int *vert_ind_arr = (unsigned int *)obj->face_arr[i].vertices;
        glLineWidth(line_width);
        glColor3f(line_color[0], line_color[1], line_color[2]);
        glDrawElements(GL_LINE_LOOP, face_len, GL_UNSIGNED_INT, vert_ind_arr);

        if (enable_points) {
          glPointSize(vertex_width);
          glColor3f(vert_color[0], vert_color[1], vert_color[2]);
          glDrawElements(GL_POINTS, face_len, GL_UNSIGNED_INT, vert_ind_arr);
        }
      }
    }
  }
};
#endif  // MYOPENGLWIDGET_H
