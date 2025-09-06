QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calc_controller.cc \
    calc_model.cc \
    credit_controller.cc \
    credit_model.cc \
    deposit_controller.cc \
    deposit_model.cc \
    main.cc \
    qcustomplot.cpp

HEADERS += \
    calc_controller.h \
    calc_model.h \
    credit_controller.h \
    credit_model.h \
    deposit_controller.h \
    deposit_model.h \
    qcustomplot.h

FORMS += \
    calc_view.ui \
    credit_view.ui \
    deposit_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
