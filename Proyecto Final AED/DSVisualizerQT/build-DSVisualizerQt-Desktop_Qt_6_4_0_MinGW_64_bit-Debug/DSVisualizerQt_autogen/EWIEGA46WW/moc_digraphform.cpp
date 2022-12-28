/****************************************************************************
** Meta object code from reading C++ file 'digraphform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DSVisualizerQt/digraphform.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'digraphform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
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
struct qt_meta_stringdata_Digraphform_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[23];
    char stringdata5[20];
    char stringdata6[23];
    char stringdata7[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Digraphform_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Digraphform_t qt_meta_stringdata_Digraphform = {
    {
        QT_MOC_LITERAL(0, 11),  // "Digraphform"
        QT_MOC_LITERAL(12, 21),  // "on_InsVertice_clicked"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 20),  // "on_InsArista_clicked"
        QT_MOC_LITERAL(56, 22),  // "on_btnDijkstra_clicked"
        QT_MOC_LITERAL(79, 19),  // "on_btnFloyd_clicked"
        QT_MOC_LITERAL(99, 22),  // "on_btnWarshall_clicked"
        QT_MOC_LITERAL(122, 19)   // "on_btn_Draw_clicked"
    },
    "Digraphform",
    "on_InsVertice_clicked",
    "",
    "on_InsArista_clicked",
    "on_btnDijkstra_clicked",
    "on_btnFloyd_clicked",
    "on_btnWarshall_clicked",
    "on_btn_Draw_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Digraphform[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Digraphform::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Digraphform.offsetsAndSizes,
    qt_meta_data_Digraphform,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Digraphform_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Digraphform, std::true_type>,
        // method 'on_InsVertice_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_InsArista_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnDijkstra_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnFloyd_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnWarshall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_Draw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Digraphform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Digraphform *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_InsVertice_clicked(); break;
        case 1: _t->on_InsArista_clicked(); break;
        case 2: _t->on_btnDijkstra_clicked(); break;
        case 3: _t->on_btnFloyd_clicked(); break;
        case 4: _t->on_btnWarshall_clicked(); break;
        case 5: _t->on_btn_Draw_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Digraphform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Digraphform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Digraphform.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Digraphform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
