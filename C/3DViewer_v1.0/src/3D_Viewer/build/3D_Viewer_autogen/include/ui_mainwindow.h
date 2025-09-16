/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "myopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    MyOpenGLWidget *oglwidget;
    QPushButton *load_obj_button;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *name_label;
    QLabel *vertices_label;
    QLabel *faces_label;
    QPushButton *save_in_jpeg;
    QPushButton *save_in_bmp;
    QPushButton *save_in_gif;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *scale;
    QSlider *Z_trans_slider;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *z_angle;
    QSlider *Y_rotation_slider;
    QSlider *X_trans_slider;
    QSlider *scaling_slider;
    QLabel *label_4;
    QLabel *x_angle;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *y_angle;
    QSlider *Y_trans_slider;
    QSlider *X_rotation_slider;
    QSlider *Z_rotation_slider;
    QLabel *label_18;
    QPushButton *reset_position;
    QLabel *label_12;
    QLabel *label_16;
    QPushButton *load_settings;
    QPushButton *save_settings;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QRadioButton *not_stipple_line;
    QRadioButton *stipple_line;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_17;
    QRadioButton *parallel_proj;
    QRadioButton *central_proj;
    QFrame *line_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSlider *vert_color_R;
    QSlider *vert_color_G;
    QSlider *vert_color_B;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_5;
    QSlider *back_color_R;
    QSlider *back_color_G;
    QSlider *back_color_B;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *line_color_R;
    QSlider *line_color_G;
    QSlider *line_color_B;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QSlider *line_width_slider;
    QLabel *label_15;
    QSlider *vertex_width_slider;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QRadioButton *circle_vert_radio;
    QRadioButton *square_vert_radio;
    QRadioButton *disable_vert_radio;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(770, 675);
        MainWindow->setMinimumSize(QSize(770, 675));
        MainWindow->setMaximumSize(QSize(770, 675));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(600, 60, 160, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(600, 10, 160, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(591, 10, 16, 170));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(750, 10, 23, 170));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        oglwidget = new MyOpenGLWidget(centralwidget);
        oglwidget->setObjectName("oglwidget");
        oglwidget->setGeometry(QRect(10, 10, 580, 362));
        load_obj_button = new QPushButton(centralwidget);
        load_obj_button->setObjectName("load_obj_button");
        load_obj_button->setGeometry(QRect(620, 20, 121, 32));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(610, 71, 83, 17));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(610, 117, 61, 17));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(610, 140, 48, 17));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        name_label = new QLabel(centralwidget);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(610, 94, 110, 17));
        name_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        vertices_label = new QLabel(centralwidget);
        vertices_label->setObjectName("vertices_label");
        vertices_label->setGeometry(QRect(680, 116, 60, 17));
        vertices_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        faces_label = new QLabel(centralwidget);
        faces_label->setObjectName("faces_label");
        faces_label->setGeometry(QRect(680, 140, 60, 17));
        faces_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        save_in_jpeg = new QPushButton(centralwidget);
        save_in_jpeg->setObjectName("save_in_jpeg");
        save_in_jpeg->setGeometry(QRect(598, 340, 162, 32));
        save_in_bmp = new QPushButton(centralwidget);
        save_in_bmp->setObjectName("save_in_bmp");
        save_in_bmp->setGeometry(QRect(598, 260, 162, 32));
        save_in_gif = new QPushButton(centralwidget);
        save_in_gif->setObjectName("save_in_gif");
        save_in_gif->setGeometry(QRect(598, 300, 162, 32));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 378, 360, 230));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scale = new QLabel(layoutWidget);
        scale->setObjectName("scale");
        scale->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(scale, 3, 1, 1, 1);

        Z_trans_slider = new QSlider(layoutWidget);
        Z_trans_slider->setObjectName("Z_trans_slider");
        Z_trans_slider->setEnabled(false);
        Z_trans_slider->setMinimum(-10000);
        Z_trans_slider->setMaximum(10000);
        Z_trans_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Z_trans_slider, 6, 1, 1, 2);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        z_angle = new QLabel(layoutWidget);
        z_angle->setObjectName("z_angle");
        z_angle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(z_angle, 2, 1, 1, 1);

        Y_rotation_slider = new QSlider(layoutWidget);
        Y_rotation_slider->setObjectName("Y_rotation_slider");
        Y_rotation_slider->setEnabled(false);
        Y_rotation_slider->setMaximum(628319);
        Y_rotation_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Y_rotation_slider, 1, 2, 1, 1);

        X_trans_slider = new QSlider(layoutWidget);
        X_trans_slider->setObjectName("X_trans_slider");
        X_trans_slider->setEnabled(false);
        X_trans_slider->setMinimum(-10000);
        X_trans_slider->setMaximum(10000);
        X_trans_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(X_trans_slider, 4, 1, 1, 2);

        scaling_slider = new QSlider(layoutWidget);
        scaling_slider->setObjectName("scaling_slider");
        scaling_slider->setEnabled(false);
        scaling_slider->setMinimum(100);
        scaling_slider->setMaximum(3000);
        scaling_slider->setSingleStep(50);
        scaling_slider->setValue(1000);
        scaling_slider->setTracking(true);
        scaling_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(scaling_slider, 3, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        x_angle = new QLabel(layoutWidget);
        x_angle->setObjectName("x_angle");
        x_angle->setLayoutDirection(Qt::LeftToRight);
        x_angle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(x_angle, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        y_angle = new QLabel(layoutWidget);
        y_angle->setObjectName("y_angle");
        y_angle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(y_angle, 1, 1, 1, 1);

        Y_trans_slider = new QSlider(layoutWidget);
        Y_trans_slider->setObjectName("Y_trans_slider");
        Y_trans_slider->setEnabled(false);
        Y_trans_slider->setMinimum(-10000);
        Y_trans_slider->setMaximum(10000);
        Y_trans_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Y_trans_slider, 5, 1, 1, 2);

        X_rotation_slider = new QSlider(layoutWidget);
        X_rotation_slider->setObjectName("X_rotation_slider");
        X_rotation_slider->setEnabled(false);
        X_rotation_slider->setMaximum(628319);
        X_rotation_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(X_rotation_slider, 0, 2, 1, 1);

        Z_rotation_slider = new QSlider(layoutWidget);
        Z_rotation_slider->setObjectName("Z_rotation_slider");
        Z_rotation_slider->setEnabled(false);
        Z_rotation_slider->setMaximum(628319);
        Z_rotation_slider->setSingleStep(1);
        Z_rotation_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(Z_rotation_slider, 2, 2, 1, 1);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(382, 515, 100, 24));
        reset_position = new QPushButton(centralwidget);
        reset_position->setObjectName("reset_position");
        reset_position->setGeometry(QRect(10, 610, 360, 32));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(383, 549, 100, 24));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(382, 582, 100, 20));
        load_settings = new QPushButton(centralwidget);
        load_settings->setObjectName("load_settings");
        load_settings->setGeometry(QRect(380, 610, 190, 32));
        save_settings = new QPushButton(centralwidget);
        save_settings->setObjectName("save_settings");
        save_settings->setGeometry(QRect(580, 610, 179, 32));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(381, 408, 377, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName("label_13");

        horizontalLayout->addWidget(label_13);

        not_stipple_line = new QRadioButton(layoutWidget1);
        not_stipple_line->setObjectName("not_stipple_line");
        not_stipple_line->setEnabled(true);
        not_stipple_line->setChecked(true);

        horizontalLayout->addWidget(not_stipple_line);

        stipple_line = new QRadioButton(layoutWidget1);
        stipple_line->setObjectName("stipple_line");

        horizontalLayout->addWidget(stipple_line);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(381, 378, 376, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName("label_17");

        horizontalLayout_2->addWidget(label_17);

        parallel_proj = new QRadioButton(layoutWidget2);
        parallel_proj->setObjectName("parallel_proj");

        horizontalLayout_2->addWidget(parallel_proj);

        central_proj = new QRadioButton(layoutWidget2);
        central_proj->setObjectName("central_proj");
        central_proj->setChecked(true);

        horizontalLayout_2->addWidget(central_proj);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(599, 179, 161, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(488, 511, 271, 34));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        vert_color_R = new QSlider(widget);
        vert_color_R->setObjectName("vert_color_R");
        vert_color_R->setTabletTracking(false);
        vert_color_R->setAutoFillBackground(false);
        vert_color_R->setMaximum(100);
        vert_color_R->setSliderPosition(100);
        vert_color_R->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(vert_color_R);

        vert_color_G = new QSlider(widget);
        vert_color_G->setObjectName("vert_color_G");
        vert_color_G->setMaximum(100);
        vert_color_G->setSliderPosition(100);
        vert_color_G->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(vert_color_G);

        vert_color_B = new QSlider(widget);
        vert_color_B->setObjectName("vert_color_B");
        vert_color_B->setMaximum(100);
        vert_color_B->setSliderPosition(100);
        vert_color_B->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(vert_color_B);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(489, 545, 271, 34));
        horizontalLayout_5 = new QHBoxLayout(widget1);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        back_color_R = new QSlider(widget1);
        back_color_R->setObjectName("back_color_R");
        back_color_R->setMaximum(100);
        back_color_R->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(back_color_R);

        back_color_G = new QSlider(widget1);
        back_color_G->setObjectName("back_color_G");
        back_color_G->setMaximum(100);
        back_color_G->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(back_color_G);

        back_color_B = new QSlider(widget1);
        back_color_B->setObjectName("back_color_B");
        back_color_B->setMaximum(100);
        back_color_B->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(back_color_B);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(489, 579, 271, 30));
        horizontalLayout_4 = new QHBoxLayout(widget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_color_R = new QSlider(widget2);
        line_color_R->setObjectName("line_color_R");
        line_color_R->setMaximum(100);
        line_color_R->setPageStep(10);
        line_color_R->setSliderPosition(100);
        line_color_R->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(line_color_R);

        line_color_G = new QSlider(widget2);
        line_color_G->setObjectName("line_color_G");
        line_color_G->setMaximum(100);
        line_color_G->setSliderPosition(100);
        line_color_G->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(line_color_G);

        line_color_B = new QSlider(widget2);
        line_color_B->setObjectName("line_color_B");
        line_color_B->setMaximum(100);
        line_color_B->setSliderPosition(100);
        line_color_B->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(line_color_B);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(380, 476, 379, 35));
        horizontalLayout_6 = new QHBoxLayout(widget3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(widget3);
        label_14->setObjectName("label_14");

        horizontalLayout_6->addWidget(label_14);

        line_width_slider = new QSlider(widget3);
        line_width_slider->setObjectName("line_width_slider");
        line_width_slider->setMaximum(30);
        line_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(line_width_slider);

        label_15 = new QLabel(widget3);
        label_15->setObjectName("label_15");

        horizontalLayout_6->addWidget(label_15);

        vertex_width_slider = new QSlider(widget3);
        vertex_width_slider->setObjectName("vertex_width_slider");
        vertex_width_slider->setMaximum(30);
        vertex_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(vertex_width_slider);

        widget4 = new QWidget(centralwidget);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(380, 440, 379, 36));
        horizontalLayout_7 = new QHBoxLayout(widget4);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(widget4);
        label_19->setObjectName("label_19");

        horizontalLayout_7->addWidget(label_19);

        circle_vert_radio = new QRadioButton(widget4);
        circle_vert_radio->setObjectName("circle_vert_radio");
        circle_vert_radio->setEnabled(true);
        circle_vert_radio->setChecked(true);

        horizontalLayout_7->addWidget(circle_vert_radio);

        square_vert_radio = new QRadioButton(widget4);
        square_vert_radio->setObjectName("square_vert_radio");
        square_vert_radio->setEnabled(true);
        square_vert_radio->setChecked(false);

        horizontalLayout_7->addWidget(square_vert_radio);

        disable_vert_radio = new QRadioButton(widget4);
        disable_vert_radio->setObjectName("disable_vert_radio");
        disable_vert_radio->setEnabled(true);
        disable_vert_radio->setChecked(false);

        horizontalLayout_7->addWidget(disable_vert_radio);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 770, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(X_rotation_slider, Y_rotation_slider);
        QWidget::setTabOrder(Y_rotation_slider, Z_rotation_slider);
        QWidget::setTabOrder(Z_rotation_slider, scaling_slider);
        QWidget::setTabOrder(scaling_slider, X_trans_slider);
        QWidget::setTabOrder(X_trans_slider, Y_trans_slider);
        QWidget::setTabOrder(Y_trans_slider, Z_trans_slider);
        QWidget::setTabOrder(Z_trans_slider, load_obj_button);
        QWidget::setTabOrder(load_obj_button, back_color_G);
        QWidget::setTabOrder(back_color_G, back_color_B);
        QWidget::setTabOrder(back_color_B, save_settings);
        QWidget::setTabOrder(save_settings, vertex_width_slider);
        QWidget::setTabOrder(vertex_width_slider, line_color_R);
        QWidget::setTabOrder(line_color_R, line_color_G);
        QWidget::setTabOrder(line_color_G, line_color_B);
        QWidget::setTabOrder(line_color_B, not_stipple_line);
        QWidget::setTabOrder(not_stipple_line, stipple_line);
        QWidget::setTabOrder(stipple_line, load_settings);
        QWidget::setTabOrder(load_settings, save_in_jpeg);
        QWidget::setTabOrder(save_in_jpeg, save_in_bmp);
        QWidget::setTabOrder(save_in_bmp, save_in_gif);
        QWidget::setTabOrder(save_in_gif, parallel_proj);
        QWidget::setTabOrder(parallel_proj, central_proj);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D Viewer v1.0", nullptr));
        load_obj_button->setText(QCoreApplication::translate("MainWindow", "Load .obj file..", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\270\320\273\320\260:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\261\320\265\321\200:", nullptr));
        name_label->setText(QString());
        vertices_label->setText(QString());
        faces_label->setText(QString());
        save_in_jpeg->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 jpeg", nullptr));
        save_in_bmp->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 bmp", nullptr));
        save_in_gif->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 gif", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "1.00", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 z:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 \321\205:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 \321\203:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 \320\276\321\201\320\270 \321\205:", nullptr));
        z_angle->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        x_angle->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \320\277\320\276 \320\276\321\201\320\270 z:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265\320\277\320\276 \320\276\321\201\320\270 \321\203:", nullptr));
        y_angle->setText(QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\320\260 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        reset_position->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214  \320\260\321\204\321\204\320\270\320\275\320\275\321\213\320\265 \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271:", nullptr));
        load_settings->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        save_settings->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\273\320\270\320\275\320\270\320\271:", nullptr));
        not_stipple_line->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        stipple_line->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270:", nullptr));
        parallel_proj->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        central_proj->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\273\320\270\320\275\320\270\320\271:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        circle_vert_radio->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        square_vert_radio->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        disable_vert_radio->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
