/****************************************************************************
** Meta object code from reading C++ file 'standarddialogs.h'
**
** Created: Fri Oct 25 07:07:40 2013
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "standarddialogs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'standarddialogs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StandardDialogs[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      31,   16,   16,   16, 0x08,
      47,   16,   16,   16, 0x08,
      59,   16,   16,   16, 0x08,
      70,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StandardDialogs[] = {
    "StandardDialogs\0\0slotPicShow()\0"
    "slotVideoShow()\0slotStart()\0slotStop()\0"
    "slotReset()\0"
};

const QMetaObject StandardDialogs::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StandardDialogs,
      qt_meta_data_StandardDialogs, 0 }
};

const QMetaObject *StandardDialogs::metaObject() const
{
    return &staticMetaObject;
}

void *StandardDialogs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StandardDialogs))
        return static_cast<void*>(const_cast< StandardDialogs*>(this));
    return QDialog::qt_metacast(_clname);
}

int StandardDialogs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotPicShow(); break;
        case 1: slotVideoShow(); break;
        case 2: slotStart(); break;
        case 3: slotStop(); break;
        case 4: slotReset(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
