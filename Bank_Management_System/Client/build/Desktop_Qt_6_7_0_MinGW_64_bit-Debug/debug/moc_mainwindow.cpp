/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onConnectionDevice",
    "",
    "onDisconnectedDevice",
    "onErrorOccurredDevice",
    "QAbstractSocket::SocketError",
    "socketError",
    "onStateChangedDevice",
    "QAbstractSocket::SocketState",
    "socketState",
    "onReadyReadDevice",
    "responseData",
    "on_pbConnect_clicked",
    "on_pbDisconnect_clicked",
    "on_pb_login_clicked",
    "on_Admin_pbCreate_new_user_clicked",
    "on_Admin_pbUpdate_user_clicked",
    "on_Admin_pbDelete_user_clicked",
    "on_Admin_pbGet_acc_number_clicked",
    "on_Admin_pbView_balance_clicked",
    "on_Admin_pbView_trans_hist_clicked",
    "on_Admin_pbView_DB_clicked",
    "on_Admin_pbLogout_clicked",
    "on_Admin_pbExit_clicked",
    "on_User_pbGet_acc_number_clicked",
    "on_User_pbView_balance_clicked",
    "on_User_pbMake_transfer_clicked",
    "on_User_pbMake_transaction_clicked",
    "on_User_pbView_trans_histroy_clicked",
    "on_User_pbLogout_clicked",
    "on_User_pbExit_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x0a,    1 /* Public */,
       3,    0,  159,    2, 0x0a,    2 /* Public */,
       4,    1,  160,    2, 0x0a,    3 /* Public */,
       7,    1,  163,    2, 0x0a,    5 /* Public */,
      10,    1,  166,    2, 0x0a,    7 /* Public */,
      12,    0,  169,    2, 0x08,    9 /* Private */,
      13,    0,  170,    2, 0x08,   10 /* Private */,
      14,    0,  171,    2, 0x08,   11 /* Private */,
      15,    0,  172,    2, 0x08,   12 /* Private */,
      16,    0,  173,    2, 0x08,   13 /* Private */,
      17,    0,  174,    2, 0x08,   14 /* Private */,
      18,    0,  175,    2, 0x08,   15 /* Private */,
      19,    0,  176,    2, 0x08,   16 /* Private */,
      20,    0,  177,    2, 0x08,   17 /* Private */,
      21,    0,  178,    2, 0x08,   18 /* Private */,
      22,    0,  179,    2, 0x08,   19 /* Private */,
      23,    0,  180,    2, 0x08,   20 /* Private */,
      24,    0,  181,    2, 0x08,   21 /* Private */,
      25,    0,  182,    2, 0x08,   22 /* Private */,
      26,    0,  183,    2, 0x08,   23 /* Private */,
      27,    0,  184,    2, 0x08,   24 /* Private */,
      28,    0,  185,    2, 0x08,   25 /* Private */,
      29,    0,  186,    2, 0x08,   26 /* Private */,
      30,    0,  187,    2, 0x08,   27 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onConnectionDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnectedDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onErrorOccurredDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'onStateChangedDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'onReadyReadDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'on_pbConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pbDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_login_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbCreate_new_user_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbUpdate_user_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbDelete_user_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbGet_acc_number_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbView_balance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbView_trans_hist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbView_DB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbLogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Admin_pbExit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbGet_acc_number_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbView_balance_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbMake_transfer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbMake_transaction_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbView_trans_histroy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbLogout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_User_pbExit_clicked'
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
        case 0: _t->onConnectionDevice(); break;
        case 1: _t->onDisconnectedDevice(); break;
        case 2: _t->onErrorOccurredDevice((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 3: _t->onStateChangedDevice((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 4: _t->onReadyReadDevice((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 5: _t->on_pbConnect_clicked(); break;
        case 6: _t->on_pbDisconnect_clicked(); break;
        case 7: _t->on_pb_login_clicked(); break;
        case 8: _t->on_Admin_pbCreate_new_user_clicked(); break;
        case 9: _t->on_Admin_pbUpdate_user_clicked(); break;
        case 10: _t->on_Admin_pbDelete_user_clicked(); break;
        case 11: _t->on_Admin_pbGet_acc_number_clicked(); break;
        case 12: _t->on_Admin_pbView_balance_clicked(); break;
        case 13: _t->on_Admin_pbView_trans_hist_clicked(); break;
        case 14: _t->on_Admin_pbView_DB_clicked(); break;
        case 15: _t->on_Admin_pbLogout_clicked(); break;
        case 16: _t->on_Admin_pbExit_clicked(); break;
        case 17: _t->on_User_pbGet_acc_number_clicked(); break;
        case 18: _t->on_User_pbView_balance_clicked(); break;
        case 19: _t->on_User_pbMake_transfer_clicked(); break;
        case 20: _t->on_User_pbMake_transaction_clicked(); break;
        case 21: _t->on_User_pbView_trans_histroy_clicked(); break;
        case 22: _t->on_User_pbLogout_clicked(); break;
        case 23: _t->on_User_pbExit_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
