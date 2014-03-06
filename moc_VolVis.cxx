/****************************************************************************
** Meta object code from reading C++ file 'VolVis.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../VolVis/VolVis.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VolVis.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VolVis[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x05,
      32,    7,    7,    7, 0x05,
      48,   42,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,    7,    7,    7, 0x0a,
      88,    7,    7,    7, 0x0a,
     112,    7,    7,    7, 0x0a,
     138,    7,    7,    7, 0x0a,
     163,    7,    7,    7, 0x0a,
     176,    7,    7,    7, 0x0a,
     191,    7,    7,    7, 0x0a,
     205,    7,    7,    7, 0x0a,
     218,    7,    7,    7, 0x0a,
     230,    7,    7,    7, 0x0a,
     244,    7,    7,    7, 0x0a,
     257,    7,    7,    7, 0x0a,
     276,    7,    7,    7, 0x0a,
     294,    7,    7,    7, 0x0a,
     311,    7,    7,    7, 0x0a,
     326,    7,    7,    7, 0x0a,
     337,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VolVis[] = {
    "VolVis\0\0value\0valueChanged(int)\0"
    "clicked()\0event\0mouseMoveEvent(QMouseEvent*)\0"
    "slotExit()\0setSliceNumberLeft(int)\0"
    "setSliceNumberCenter(int)\0"
    "setSliceNumberRight(int)\0renderLeft()\0"
    "renderCenter()\0renderRight()\0renderMain()\0"
    "clearleft()\0clearcenter()\0clearright()\0"
    "renderGreenColor()\0renderBlueColor()\0"
    "renderRedColor()\0renderEraser()\0"
    "trainSVM()\0updateImageArrayafterTraining()\0"
};

void VolVis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VolVis *_t = static_cast<VolVis *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->clicked(); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->slotExit(); break;
        case 4: _t->setSliceNumberLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setSliceNumberCenter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setSliceNumberRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->renderLeft(); break;
        case 8: _t->renderCenter(); break;
        case 9: _t->renderRight(); break;
        case 10: _t->renderMain(); break;
        case 11: _t->clearleft(); break;
        case 12: _t->clearcenter(); break;
        case 13: _t->clearright(); break;
        case 14: _t->renderGreenColor(); break;
        case 15: _t->renderBlueColor(); break;
        case 16: _t->renderRedColor(); break;
        case 17: _t->renderEraser(); break;
        case 18: _t->trainSVM(); break;
        case 19: _t->updateImageArrayafterTraining(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VolVis::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VolVis::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VolVis,
      qt_meta_data_VolVis, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VolVis::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VolVis::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VolVis::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VolVis))
        return static_cast<void*>(const_cast< VolVis*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VolVis::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void VolVis::valueChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VolVis::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void VolVis::mouseMoveEvent(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
