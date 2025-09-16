/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[31];
    char stringdata5[6];
    char stringdata6[14];
    char stringdata7[13];
    char stringdata8[10];
    char stringdata9[27];
    char stringdata10[25];
    char stringdata11[25];
    char stringdata12[34];
    char stringdata13[36];
    char stringdata14[24];
    char stringdata15[23];
    char stringdata16[23];
    char stringdata17[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 15),  // "slider_rotation"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 18),  // "slider_translation"
        QT_MOC_LITERAL(47, 30),  // "on_scaling_slider_valueChanged"
        QT_MOC_LITERAL(78, 5),  // "value"
        QT_MOC_LITERAL(84, 13),  // "radio_clicked"
        QT_MOC_LITERAL(98, 12),  // "set_defaults"
        QT_MOC_LITERAL(111, 9),  // "set_color"
        QT_MOC_LITERAL(121, 26),  // "on_load_obj_button_clicked"
        QT_MOC_LITERAL(148, 24),  // "on_save_settings_clicked"
        QT_MOC_LITERAL(173, 24),  // "on_load_settings_clicked"
        QT_MOC_LITERAL(198, 33),  // "on_line_width_slider_valueCha..."
        QT_MOC_LITERAL(232, 35),  // "on_vertex_width_slider_valueC..."
        QT_MOC_LITERAL(268, 23),  // "on_save_in_jpeg_clicked"
        QT_MOC_LITERAL(292, 22),  // "on_save_in_bmp_clicked"
        QT_MOC_LITERAL(315, 22),  // "on_save_in_gif_clicked"
        QT_MOC_LITERAL(338, 26)   // "on_reset_position_released"
    },
    "MainWindow",
    "slider_rotation",
    "",
    "slider_translation",
    "on_scaling_slider_valueChanged",
    "value",
    "radio_clicked",
    "set_defaults",
    "set_color",
    "on_load_obj_button_clicked",
    "on_save_settings_clicked",
    "on_load_settings_clicked",
    "on_line_width_slider_valueChanged",
    "on_vertex_width_slider_valueChanged",
    "on_save_in_jpeg_clicked",
    "on_save_in_bmp_clicked",
    "on_save_in_gif_clicked",
    "on_reset_position_released"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    1,  106,    2, 0x08,    3 /* Private */,
       6,    0,  109,    2, 0x08,    5 /* Private */,
       7,    0,  110,    2, 0x08,    6 /* Private */,
       8,    0,  111,    2, 0x08,    7 /* Private */,
       9,    0,  112,    2, 0x08,    8 /* Private */,
      10,    0,  113,    2, 0x08,    9 /* Private */,
      11,    0,  114,    2, 0x08,   10 /* Private */,
      12,    1,  115,    2, 0x08,   11 /* Private */,
      13,    1,  118,    2, 0x08,   13 /* Private */,
      14,    0,  121,    2, 0x08,   15 /* Private */,
      15,    0,  122,    2, 0x08,   16 /* Private */,
      16,    0,  123,    2, 0x08,   17 /* Private */,
      17,    0,  124,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'slider_rotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slider_translation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scaling_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'radio_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_defaults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_color'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_load_obj_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_settings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_load_settings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_line_width_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_vertex_width_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_save_in_jpeg_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_in_bmp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_in_gif_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_reset_position_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slider_rotation(); break;
        case 1: _t->slider_translation(); break;
        case 2: _t->on_scaling_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->radio_clicked(); break;
        case 4: _t->set_defaults(); break;
        case 5: _t->set_color(); break;
        case 6: _t->on_load_obj_button_clicked(); break;
        case 7: _t->on_save_settings_clicked(); break;
        case 8: _t->on_load_settings_clicked(); break;
        case 9: _t->on_line_width_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_vertex_width_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_save_in_jpeg_clicked(); break;
        case 12: _t->on_save_in_bmp_clicked(); break;
        case 13: _t->on_save_in_gif_clicked(); break;
        case 14: _t->on_reset_position_released(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
