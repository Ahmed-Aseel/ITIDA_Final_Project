/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *Tab;
    QWidget *Connect;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_1;
    QGroupBox *gbConnection;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *ldl_ServerIP;
    QLineEdit *Connect_IP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_PortNmber;
    QLineEdit *Connect_Port;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QVBoxLayout *verticalLayout;
    QListWidget *lw_Connect;
    QPushButton *Connect_pbClear;
    QWidget *Login;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Username;
    QLineEdit *Login_Username;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Password;
    QLineEdit *Login_Password;
    QPushButton *pb_login;
    QVBoxLayout *verticalLayout_3;
    QListWidget *lw_Login;
    QPushButton *Login_pbClear;
    QWidget *Admin;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_12;
    QLabel *lb_title_createUser;
    QLabel *Admin_lbCreate_user_error;
    QHBoxLayout *horizontalLayout_23;
    QLabel *Admin_lbCreate_user_name;
    QLineEdit *Admin_leCreate_user_name;
    QHBoxLayout *horizontalLayout_25;
    QLabel *Admin_lbCreate_user_pw;
    QLineEdit *Admin_leCreate_user_pw;
    QHBoxLayout *horizontalLayout_17;
    QLabel *Admin_lbCreate_user_full;
    QLineEdit *Admin_leCreate_user_full;
    QHBoxLayout *horizontalLayout_26;
    QLabel *Admin_lbCreate_user_age;
    QLineEdit *Admin_leCreate_user_age;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *Admin_pbCreate_new_user;
    QCheckBox *Admin_chkbox_CreateUser;
    QVBoxLayout *verticalLayout_11;
    QLabel *lb_title_updateUser;
    QLabel *Admin_lbUpdate_user_error;
    QHBoxLayout *horizontalLayout_46;
    QLabel *Admin_lbUpdate_user_acc;
    QLineEdit *Admin_leUpdate_user_acc;
    QHBoxLayout *horizontalLayout_24;
    QLabel *Admin_lbUpdate_user_name;
    QLineEdit *Admin_leUpdate_user_name;
    QHBoxLayout *horizontalLayout_32;
    QLabel *Admin_lbUpdate_user_pw;
    QLineEdit *Admin_leUpdate_user_pw;
    QHBoxLayout *horizontalLayout_19;
    QLabel *Admin_lbUpdate_user_full;
    QLineEdit *Admin_leUpdate_user_full;
    QHBoxLayout *horizontalLayout_37;
    QLabel *Admin_lbUpdate_user_age;
    QLineEdit *Admin_leUpdate_user_age;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *Admin_pbUpdate_user;
    QCheckBox *Admin_chkbox_UpdateUser;
    QVBoxLayout *verticalLayout_13;
    QLabel *lb_title_deleteUser;
    QLabel *Admin_lbDelete_user_error;
    QHBoxLayout *horizontalLayout_47;
    QLabel *Admin_lbDelete_user_acc;
    QLineEdit *Admin_leDelete_user_acc;
    QPushButton *Admin_pbDelete_user;
    QVBoxLayout *verticalLayout_14;
    QLabel *Admin_lbAcc_number;
    QHBoxLayout *horizontalLayout_27;
    QLabel *Admin_lbGet_accNo_name;
    QLineEdit *Admin_leGet_accNo_name;
    QPushButton *Admin_pbGet_acc_number;
    QVBoxLayout *verticalLayout_15;
    QLabel *Admin_lbView_balance;
    QHBoxLayout *horizontalLayout_48;
    QLabel *Admin_lbView_bal_acc;
    QLineEdit *Admin_leView_bal_acc;
    QPushButton *Admin_pbView_balance;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lbl_title_database;
    QPushButton *Admin_pbView_DB;
    QLabel *Admin_lbView_DB_error;
    QTableWidget *Admin_tbView_DB;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *Admin_lbView_trans_history;
    QPushButton *Admin_pbView_trans_hist;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *Admin_lbHistory_acc;
    QLineEdit *Admin_leHistory_acc;
    QHBoxLayout *horizontalLayout_12;
    QLabel *Admin_lbHistory_count;
    QLineEdit *Admin_leHistory_count;
    QLabel *Admin_lbView_history_error;
    QTableWidget *Admin_tbView_histroy;
    QVBoxLayout *verticalLayout_17;
    QPushButton *Admin_pbLogout;
    QPushButton *Admin_pbExit;
    QWidget *User;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_28;
    QHBoxLayout *horizontalLayout_33;
    QVBoxLayout *verticalLayout_19;
    QLabel *User_lbAcc_number;
    QPushButton *User_pbGet_acc_number;
    QVBoxLayout *verticalLayout_20;
    QLabel *User_lbView_balance;
    QPushButton *User_pbView_balance;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_22;
    QLabel *lb_title_trasfer;
    QHBoxLayout *horizontalLayout_35;
    QLabel *User_lbTo_acc_number;
    QLineEdit *User_leTo_acc_number;
    QHBoxLayout *horizontalLayout_36;
    QLabel *User_lbTransfe_amout;
    QLineEdit *User_leTrnsfr_amount;
    QLabel *User_lbMake_trnsf_error;
    QPushButton *User_pbMake_transfer;
    QVBoxLayout *verticalLayout_21;
    QLabel *lb_title_trasnaction;
    QHBoxLayout *horizontalLayout_34;
    QLabel *User_lbAmount;
    QLineEdit *User_leTrnsct_amount;
    QLabel *User_lbTransaction_error;
    QPushButton *User_pbMake_transaction;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *User_lbView_trans_history;
    QHBoxLayout *horizontalLayout_9;
    QLabel *User_lbHistory_count;
    QLineEdit *User_leHistory_count;
    QPushButton *User_pbView_trans_histroy;
    QLabel *User_lbView_history_error;
    QTableWidget *User_tbView_histroy;
    QVBoxLayout *verticalLayout_8;
    QPushButton *User_pbLogout;
    QPushButton *User_pbExit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1307, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 1281, 841));
        Tab = new QTabWidget(groupBox);
        Tab->setObjectName("Tab");
        Tab->setGeometry(QRect(10, 30, 1261, 771));
        Connect = new QWidget();
        Connect->setObjectName("Connect");
        gridLayout_4 = new QGridLayout(Connect);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_1 = new QLabel(Connect);
        label_1->setObjectName("label_1");
        QFont font;
        font.setBold(true);
        label_1->setFont(font);
        label_1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font-size:40px;\n"
"font-weight: bold;\n"
"color: rgb(0, 0, 127);\n"
"\n"
"}"));
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_1);

        gbConnection = new QGroupBox(Connect);
        gbConnection->setObjectName("gbConnection");
        gridLayout_2 = new QGridLayout(gbConnection);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ldl_ServerIP = new QLabel(gbConnection);
        ldl_ServerIP->setObjectName("ldl_ServerIP");
        ldl_ServerIP->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(ldl_ServerIP);

        Connect_IP = new QLineEdit(gbConnection);
        Connect_IP->setObjectName("Connect_IP");

        horizontalLayout->addWidget(Connect_IP);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_PortNmber = new QLabel(gbConnection);
        lbl_PortNmber->setObjectName("lbl_PortNmber");
        lbl_PortNmber->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(lbl_PortNmber);

        Connect_Port = new QLineEdit(gbConnection);
        Connect_Port->setObjectName("Connect_Port");

        horizontalLayout_2->addWidget(Connect_Port);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pbConnect = new QPushButton(gbConnection);
        pbConnect->setObjectName("pbConnect");
        pbConnect->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(0, 255, 0);"));

        horizontalLayout_3->addWidget(pbConnect);

        pbDisconnect = new QPushButton(gbConnection);
        pbDisconnect->setObjectName("pbDisconnect");
        pbDisconnect->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_3->addWidget(pbDisconnect);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lw_Connect = new QListWidget(gbConnection);
        lw_Connect->setObjectName("lw_Connect");
        lw_Connect->setEnabled(true);
        lw_Connect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lw_Connect->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lw_Connect->setAutoScroll(true);
        lw_Connect->setProperty("showDropIndicator", QVariant(true));
        lw_Connect->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        lw_Connect->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(lw_Connect);

        Connect_pbClear = new QPushButton(gbConnection);
        Connect_pbClear->setObjectName("Connect_pbClear");
        Connect_pbClear->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(Connect_pbClear);


        horizontalLayout_6->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        verticalLayout_6->addWidget(gbConnection);


        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);

        Tab->addTab(Connect, QString());
        Login = new QWidget();
        Login->setObjectName("Login");
        gridLayout_3 = new QGridLayout(Login);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_Username = new QLabel(Login);
        label_Username->setObjectName("label_Username");
        label_Username->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(label_Username);

        Login_Username = new QLineEdit(Login);
        Login_Username->setObjectName("Login_Username");

        horizontalLayout_4->addWidget(Login_Username);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_Password = new QLabel(Login);
        label_Password->setObjectName("label_Password");
        label_Password->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_5->addWidget(label_Password);

        Login_Password = new QLineEdit(Login);
        Login_Password->setObjectName("Login_Password");
        Login_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(Login_Password);


        verticalLayout_2->addLayout(horizontalLayout_5);

        pb_login = new QPushButton(Login);
        pb_login->setObjectName("pb_login");
        pb_login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(0, 255, 0);"));

        verticalLayout_2->addWidget(pb_login);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lw_Login = new QListWidget(Login);
        lw_Login->setObjectName("lw_Login");
        lw_Login->setEnabled(true);
        lw_Login->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lw_Login->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lw_Login->setAutoScroll(true);
        lw_Login->setProperty("showDropIndicator", QVariant(true));
        lw_Login->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        lw_Login->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout_3->addWidget(lw_Login);

        Login_pbClear = new QPushButton(Login);
        Login_pbClear->setObjectName("Login_pbClear");
        Login_pbClear->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));

        verticalLayout_3->addWidget(Login_pbClear);


        horizontalLayout_7->addLayout(verticalLayout_3);


        gridLayout_3->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        Tab->addTab(Login, QString());
        Admin = new QWidget();
        Admin->setObjectName("Admin");
        gridLayout = new QGridLayout(Admin);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        lb_title_createUser = new QLabel(Admin);
        lb_title_createUser->setObjectName("lb_title_createUser");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(16);
        font1.setBold(true);
        lb_title_createUser->setFont(font1);

        verticalLayout_12->addWidget(lb_title_createUser);

        Admin_lbCreate_user_error = new QLabel(Admin);
        Admin_lbCreate_user_error->setObjectName("Admin_lbCreate_user_error");

        verticalLayout_12->addWidget(Admin_lbCreate_user_error);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        Admin_lbCreate_user_name = new QLabel(Admin);
        Admin_lbCreate_user_name->setObjectName("Admin_lbCreate_user_name");

        horizontalLayout_23->addWidget(Admin_lbCreate_user_name);

        Admin_leCreate_user_name = new QLineEdit(Admin);
        Admin_leCreate_user_name->setObjectName("Admin_leCreate_user_name");

        horizontalLayout_23->addWidget(Admin_leCreate_user_name);


        verticalLayout_12->addLayout(horizontalLayout_23);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        Admin_lbCreate_user_pw = new QLabel(Admin);
        Admin_lbCreate_user_pw->setObjectName("Admin_lbCreate_user_pw");

        horizontalLayout_25->addWidget(Admin_lbCreate_user_pw);

        Admin_leCreate_user_pw = new QLineEdit(Admin);
        Admin_leCreate_user_pw->setObjectName("Admin_leCreate_user_pw");

        horizontalLayout_25->addWidget(Admin_leCreate_user_pw);


        verticalLayout_12->addLayout(horizontalLayout_25);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        Admin_lbCreate_user_full = new QLabel(Admin);
        Admin_lbCreate_user_full->setObjectName("Admin_lbCreate_user_full");

        horizontalLayout_17->addWidget(Admin_lbCreate_user_full);

        Admin_leCreate_user_full = new QLineEdit(Admin);
        Admin_leCreate_user_full->setObjectName("Admin_leCreate_user_full");

        horizontalLayout_17->addWidget(Admin_leCreate_user_full);


        verticalLayout_12->addLayout(horizontalLayout_17);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        Admin_lbCreate_user_age = new QLabel(Admin);
        Admin_lbCreate_user_age->setObjectName("Admin_lbCreate_user_age");

        horizontalLayout_26->addWidget(Admin_lbCreate_user_age);

        Admin_leCreate_user_age = new QLineEdit(Admin);
        Admin_leCreate_user_age->setObjectName("Admin_leCreate_user_age");

        horizontalLayout_26->addWidget(Admin_leCreate_user_age);


        verticalLayout_12->addLayout(horizontalLayout_26);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        Admin_pbCreate_new_user = new QPushButton(Admin);
        Admin_pbCreate_new_user->setObjectName("Admin_pbCreate_new_user");
        Admin_pbCreate_new_user->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_18->addWidget(Admin_pbCreate_new_user);

        Admin_chkbox_CreateUser = new QCheckBox(Admin);
        Admin_chkbox_CreateUser->setObjectName("Admin_chkbox_CreateUser");

        horizontalLayout_18->addWidget(Admin_chkbox_CreateUser);


        verticalLayout_12->addLayout(horizontalLayout_18);


        horizontalLayout_15->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        lb_title_updateUser = new QLabel(Admin);
        lb_title_updateUser->setObjectName("lb_title_updateUser");
        lb_title_updateUser->setFont(font1);

        verticalLayout_11->addWidget(lb_title_updateUser);

        Admin_lbUpdate_user_error = new QLabel(Admin);
        Admin_lbUpdate_user_error->setObjectName("Admin_lbUpdate_user_error");

        verticalLayout_11->addWidget(Admin_lbUpdate_user_error);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName("horizontalLayout_46");
        Admin_lbUpdate_user_acc = new QLabel(Admin);
        Admin_lbUpdate_user_acc->setObjectName("Admin_lbUpdate_user_acc");

        horizontalLayout_46->addWidget(Admin_lbUpdate_user_acc);

        Admin_leUpdate_user_acc = new QLineEdit(Admin);
        Admin_leUpdate_user_acc->setObjectName("Admin_leUpdate_user_acc");

        horizontalLayout_46->addWidget(Admin_leUpdate_user_acc);


        verticalLayout_11->addLayout(horizontalLayout_46);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        Admin_lbUpdate_user_name = new QLabel(Admin);
        Admin_lbUpdate_user_name->setObjectName("Admin_lbUpdate_user_name");

        horizontalLayout_24->addWidget(Admin_lbUpdate_user_name);

        Admin_leUpdate_user_name = new QLineEdit(Admin);
        Admin_leUpdate_user_name->setObjectName("Admin_leUpdate_user_name");

        horizontalLayout_24->addWidget(Admin_leUpdate_user_name);


        verticalLayout_11->addLayout(horizontalLayout_24);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        Admin_lbUpdate_user_pw = new QLabel(Admin);
        Admin_lbUpdate_user_pw->setObjectName("Admin_lbUpdate_user_pw");

        horizontalLayout_32->addWidget(Admin_lbUpdate_user_pw);

        Admin_leUpdate_user_pw = new QLineEdit(Admin);
        Admin_leUpdate_user_pw->setObjectName("Admin_leUpdate_user_pw");

        horizontalLayout_32->addWidget(Admin_leUpdate_user_pw);


        verticalLayout_11->addLayout(horizontalLayout_32);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        Admin_lbUpdate_user_full = new QLabel(Admin);
        Admin_lbUpdate_user_full->setObjectName("Admin_lbUpdate_user_full");

        horizontalLayout_19->addWidget(Admin_lbUpdate_user_full);

        Admin_leUpdate_user_full = new QLineEdit(Admin);
        Admin_leUpdate_user_full->setObjectName("Admin_leUpdate_user_full");

        horizontalLayout_19->addWidget(Admin_leUpdate_user_full);


        verticalLayout_11->addLayout(horizontalLayout_19);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName("horizontalLayout_37");
        Admin_lbUpdate_user_age = new QLabel(Admin);
        Admin_lbUpdate_user_age->setObjectName("Admin_lbUpdate_user_age");

        horizontalLayout_37->addWidget(Admin_lbUpdate_user_age);

        Admin_leUpdate_user_age = new QLineEdit(Admin);
        Admin_leUpdate_user_age->setObjectName("Admin_leUpdate_user_age");

        horizontalLayout_37->addWidget(Admin_leUpdate_user_age);


        verticalLayout_11->addLayout(horizontalLayout_37);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        Admin_pbUpdate_user = new QPushButton(Admin);
        Admin_pbUpdate_user->setObjectName("Admin_pbUpdate_user");
        Admin_pbUpdate_user->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_20->addWidget(Admin_pbUpdate_user);

        Admin_chkbox_UpdateUser = new QCheckBox(Admin);
        Admin_chkbox_UpdateUser->setObjectName("Admin_chkbox_UpdateUser");

        horizontalLayout_20->addWidget(Admin_chkbox_UpdateUser);


        verticalLayout_11->addLayout(horizontalLayout_20);


        horizontalLayout_15->addLayout(verticalLayout_11);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        lb_title_deleteUser = new QLabel(Admin);
        lb_title_deleteUser->setObjectName("lb_title_deleteUser");
        lb_title_deleteUser->setFont(font1);

        verticalLayout_13->addWidget(lb_title_deleteUser);

        Admin_lbDelete_user_error = new QLabel(Admin);
        Admin_lbDelete_user_error->setObjectName("Admin_lbDelete_user_error");

        verticalLayout_13->addWidget(Admin_lbDelete_user_error);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setObjectName("horizontalLayout_47");
        Admin_lbDelete_user_acc = new QLabel(Admin);
        Admin_lbDelete_user_acc->setObjectName("Admin_lbDelete_user_acc");

        horizontalLayout_47->addWidget(Admin_lbDelete_user_acc);

        Admin_leDelete_user_acc = new QLineEdit(Admin);
        Admin_leDelete_user_acc->setObjectName("Admin_leDelete_user_acc");

        horizontalLayout_47->addWidget(Admin_leDelete_user_acc);


        verticalLayout_13->addLayout(horizontalLayout_47);

        Admin_pbDelete_user = new QPushButton(Admin);
        Admin_pbDelete_user->setObjectName("Admin_pbDelete_user");
        Admin_pbDelete_user->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(Admin_pbDelete_user);


        horizontalLayout_15->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        Admin_lbAcc_number = new QLabel(Admin);
        Admin_lbAcc_number->setObjectName("Admin_lbAcc_number");
        QFont font2;
        font2.setPointSize(16);
        Admin_lbAcc_number->setFont(font2);

        verticalLayout_14->addWidget(Admin_lbAcc_number);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        Admin_lbGet_accNo_name = new QLabel(Admin);
        Admin_lbGet_accNo_name->setObjectName("Admin_lbGet_accNo_name");

        horizontalLayout_27->addWidget(Admin_lbGet_accNo_name);

        Admin_leGet_accNo_name = new QLineEdit(Admin);
        Admin_leGet_accNo_name->setObjectName("Admin_leGet_accNo_name");

        horizontalLayout_27->addWidget(Admin_leGet_accNo_name);


        verticalLayout_14->addLayout(horizontalLayout_27);

        Admin_pbGet_acc_number = new QPushButton(Admin);
        Admin_pbGet_acc_number->setObjectName("Admin_pbGet_acc_number");
        Admin_pbGet_acc_number->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_14->addWidget(Admin_pbGet_acc_number);


        horizontalLayout_15->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        Admin_lbView_balance = new QLabel(Admin);
        Admin_lbView_balance->setObjectName("Admin_lbView_balance");
        Admin_lbView_balance->setFont(font2);

        verticalLayout_15->addWidget(Admin_lbView_balance);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName("horizontalLayout_48");
        Admin_lbView_bal_acc = new QLabel(Admin);
        Admin_lbView_bal_acc->setObjectName("Admin_lbView_bal_acc");

        horizontalLayout_48->addWidget(Admin_lbView_bal_acc);

        Admin_leView_bal_acc = new QLineEdit(Admin);
        Admin_leView_bal_acc->setObjectName("Admin_leView_bal_acc");

        horizontalLayout_48->addWidget(Admin_leView_bal_acc);


        verticalLayout_15->addLayout(horizontalLayout_48);

        Admin_pbView_balance = new QPushButton(Admin);
        Admin_pbView_balance->setObjectName("Admin_pbView_balance");
        Admin_pbView_balance->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_15->addWidget(Admin_pbView_balance);


        horizontalLayout_15->addLayout(verticalLayout_15);


        verticalLayout_18->addLayout(horizontalLayout_15);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lbl_title_database = new QLabel(Admin);
        lbl_title_database->setObjectName("lbl_title_database");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(24);
        font3.setBold(true);
        lbl_title_database->setFont(font3);

        horizontalLayout_11->addWidget(lbl_title_database);

        Admin_pbView_DB = new QPushButton(Admin);
        Admin_pbView_DB->setObjectName("Admin_pbView_DB");
        Admin_pbView_DB->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_11->addWidget(Admin_pbView_DB);


        verticalLayout_16->addLayout(horizontalLayout_11);

        Admin_lbView_DB_error = new QLabel(Admin);
        Admin_lbView_DB_error->setObjectName("Admin_lbView_DB_error");

        verticalLayout_16->addWidget(Admin_lbView_DB_error);

        Admin_tbView_DB = new QTableWidget(Admin);
        if (Admin_tbView_DB->columnCount() < 6)
            Admin_tbView_DB->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Admin_tbView_DB->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        Admin_tbView_DB->setObjectName("Admin_tbView_DB");

        verticalLayout_16->addWidget(Admin_tbView_DB);


        horizontalLayout_21->addLayout(verticalLayout_16);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        Admin_lbView_trans_history = new QLabel(Admin);
        Admin_lbView_trans_history->setObjectName("Admin_lbView_trans_history");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(18);
        font4.setBold(true);
        Admin_lbView_trans_history->setFont(font4);

        horizontalLayout_16->addWidget(Admin_lbView_trans_history);

        Admin_pbView_trans_hist = new QPushButton(Admin);
        Admin_pbView_trans_hist->setObjectName("Admin_pbView_trans_hist");
        Admin_pbView_trans_hist->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_16->addWidget(Admin_pbView_trans_hist);


        verticalLayout_10->addLayout(horizontalLayout_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        Admin_lbHistory_acc = new QLabel(Admin);
        Admin_lbHistory_acc->setObjectName("Admin_lbHistory_acc");

        horizontalLayout_13->addWidget(Admin_lbHistory_acc);

        Admin_leHistory_acc = new QLineEdit(Admin);
        Admin_leHistory_acc->setObjectName("Admin_leHistory_acc");

        horizontalLayout_13->addWidget(Admin_leHistory_acc);


        horizontalLayout_14->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        Admin_lbHistory_count = new QLabel(Admin);
        Admin_lbHistory_count->setObjectName("Admin_lbHistory_count");

        horizontalLayout_12->addWidget(Admin_lbHistory_count);

        Admin_leHistory_count = new QLineEdit(Admin);
        Admin_leHistory_count->setObjectName("Admin_leHistory_count");

        horizontalLayout_12->addWidget(Admin_leHistory_count);


        horizontalLayout_14->addLayout(horizontalLayout_12);


        verticalLayout_10->addLayout(horizontalLayout_14);

        Admin_lbView_history_error = new QLabel(Admin);
        Admin_lbView_history_error->setObjectName("Admin_lbView_history_error");

        verticalLayout_10->addWidget(Admin_lbView_history_error);

        Admin_tbView_histroy = new QTableWidget(Admin);
        if (Admin_tbView_histroy->columnCount() < 4)
            Admin_tbView_histroy->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Admin_tbView_histroy->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Admin_tbView_histroy->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Admin_tbView_histroy->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Admin_tbView_histroy->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        Admin_tbView_histroy->setObjectName("Admin_tbView_histroy");
        Admin_tbView_histroy->setDragEnabled(false);

        verticalLayout_10->addWidget(Admin_tbView_histroy);


        horizontalLayout_21->addLayout(verticalLayout_10);


        verticalLayout_18->addLayout(horizontalLayout_21);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        Admin_pbLogout = new QPushButton(Admin);
        Admin_pbLogout->setObjectName("Admin_pbLogout");
        Admin_pbLogout->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));

        verticalLayout_17->addWidget(Admin_pbLogout);

        Admin_pbExit = new QPushButton(Admin);
        Admin_pbExit->setObjectName("Admin_pbExit");
        Admin_pbExit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));

        verticalLayout_17->addWidget(Admin_pbExit);


        verticalLayout_18->addLayout(verticalLayout_17);


        gridLayout->addLayout(verticalLayout_18, 0, 0, 1, 1);

        Tab->addTab(Admin, QString());
        User = new QWidget();
        User->setObjectName("User");
        gridLayout_5 = new QGridLayout(User);
        gridLayout_5->setObjectName("gridLayout_5");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName("horizontalLayout_33");
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        User_lbAcc_number = new QLabel(User);
        User_lbAcc_number->setObjectName("User_lbAcc_number");
        User_lbAcc_number->setFont(font2);

        verticalLayout_19->addWidget(User_lbAcc_number);

        User_pbGet_acc_number = new QPushButton(User);
        User_pbGet_acc_number->setObjectName("User_pbGet_acc_number");
        User_pbGet_acc_number->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_19->addWidget(User_pbGet_acc_number);


        horizontalLayout_33->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        User_lbView_balance = new QLabel(User);
        User_lbView_balance->setObjectName("User_lbView_balance");
        User_lbView_balance->setFont(font2);

        verticalLayout_20->addWidget(User_lbView_balance);

        User_pbView_balance = new QPushButton(User);
        User_pbView_balance->setObjectName("User_pbView_balance");
        User_pbView_balance->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_20->addWidget(User_pbView_balance);


        horizontalLayout_33->addLayout(verticalLayout_20);


        horizontalLayout_28->addLayout(horizontalLayout_33);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName("verticalLayout_22");
        lb_title_trasfer = new QLabel(User);
        lb_title_trasfer->setObjectName("lb_title_trasfer");
        lb_title_trasfer->setFont(font4);

        verticalLayout_22->addWidget(lb_title_trasfer);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        User_lbTo_acc_number = new QLabel(User);
        User_lbTo_acc_number->setObjectName("User_lbTo_acc_number");

        horizontalLayout_35->addWidget(User_lbTo_acc_number);

        User_leTo_acc_number = new QLineEdit(User);
        User_leTo_acc_number->setObjectName("User_leTo_acc_number");

        horizontalLayout_35->addWidget(User_leTo_acc_number);


        verticalLayout_22->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        User_lbTransfe_amout = new QLabel(User);
        User_lbTransfe_amout->setObjectName("User_lbTransfe_amout");

        horizontalLayout_36->addWidget(User_lbTransfe_amout);

        User_leTrnsfr_amount = new QLineEdit(User);
        User_leTrnsfr_amount->setObjectName("User_leTrnsfr_amount");

        horizontalLayout_36->addWidget(User_leTrnsfr_amount);


        verticalLayout_22->addLayout(horizontalLayout_36);

        User_lbMake_trnsf_error = new QLabel(User);
        User_lbMake_trnsf_error->setObjectName("User_lbMake_trnsf_error");

        verticalLayout_22->addWidget(User_lbMake_trnsf_error);

        User_pbMake_transfer = new QPushButton(User);
        User_pbMake_transfer->setObjectName("User_pbMake_transfer");
        User_pbMake_transfer->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        verticalLayout_22->addWidget(User_pbMake_transfer);


        horizontalLayout_8->addLayout(verticalLayout_22);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        lb_title_trasnaction = new QLabel(User);
        lb_title_trasnaction->setObjectName("lb_title_trasnaction");
        lb_title_trasnaction->setFont(font4);

        verticalLayout_21->addWidget(lb_title_trasnaction);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName("horizontalLayout_34");
        User_lbAmount = new QLabel(User);
        User_lbAmount->setObjectName("User_lbAmount");

        horizontalLayout_34->addWidget(User_lbAmount);

        User_leTrnsct_amount = new QLineEdit(User);
        User_leTrnsct_amount->setObjectName("User_leTrnsct_amount");

        horizontalLayout_34->addWidget(User_leTrnsct_amount);


        verticalLayout_21->addLayout(horizontalLayout_34);

        User_lbTransaction_error = new QLabel(User);
        User_lbTransaction_error->setObjectName("User_lbTransaction_error");

        verticalLayout_21->addWidget(User_lbTransaction_error);

        User_pbMake_transaction = new QPushButton(User);
        User_pbMake_transaction->setObjectName("User_pbMake_transaction");
        User_pbMake_transaction->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
""));

        verticalLayout_21->addWidget(User_pbMake_transaction);


        horizontalLayout_8->addLayout(verticalLayout_21);


        horizontalLayout_28->addLayout(horizontalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_28);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        User_lbView_trans_history = new QLabel(User);
        User_lbView_trans_history->setObjectName("User_lbView_trans_history");
        User_lbView_trans_history->setFont(font4);

        horizontalLayout_10->addWidget(User_lbView_trans_history);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        User_lbHistory_count = new QLabel(User);
        User_lbHistory_count->setObjectName("User_lbHistory_count");

        horizontalLayout_9->addWidget(User_lbHistory_count);

        User_leHistory_count = new QLineEdit(User);
        User_leHistory_count->setObjectName("User_leHistory_count");

        horizontalLayout_9->addWidget(User_leHistory_count);


        horizontalLayout_10->addLayout(horizontalLayout_9);

        User_pbView_trans_histroy = new QPushButton(User);
        User_pbView_trans_histroy->setObjectName("User_pbView_trans_histroy");
        User_pbView_trans_histroy->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_10->addWidget(User_pbView_trans_histroy);


        verticalLayout_7->addLayout(horizontalLayout_10);

        User_lbView_history_error = new QLabel(User);
        User_lbView_history_error->setObjectName("User_lbView_history_error");

        verticalLayout_7->addWidget(User_lbView_history_error);

        User_tbView_histroy = new QTableWidget(User);
        if (User_tbView_histroy->columnCount() < 4)
            User_tbView_histroy->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        User_tbView_histroy->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        User_tbView_histroy->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        User_tbView_histroy->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        User_tbView_histroy->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        User_tbView_histroy->setObjectName("User_tbView_histroy");

        verticalLayout_7->addWidget(User_tbView_histroy);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        User_pbLogout = new QPushButton(User);
        User_pbLogout->setObjectName("User_pbLogout");
        User_pbLogout->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));

        verticalLayout_8->addWidget(User_pbLogout);

        User_pbExit = new QPushButton(User);
        User_pbExit->setObjectName("User_pbExit");
        User_pbExit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 0, 0);"));

        verticalLayout_8->addWidget(User_pbExit);


        verticalLayout_9->addLayout(verticalLayout_8);


        gridLayout_5->addLayout(verticalLayout_9, 0, 0, 1, 1);

        Tab->addTab(User, QString());
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1307, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(Connect_pbClear, &QPushButton::clicked, lw_Connect, qOverload<>(&QListWidget::clear));
        QObject::connect(Login_pbClear, &QPushButton::clicked, lw_Login, qOverload<>(&QListWidget::clear));

        Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Bank System", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">CoreTech Innovations - IMT School</span></p><p align=\"center\"><span style=\" font-size:20pt;\">Welcome To Bank System</span></p><p align=\"center\"><span style=\" font-size:20pt;\">Developed By: Ahmed Aseel</span></p></body></html>", nullptr));
        gbConnection->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        ldl_ServerIP->setText(QCoreApplication::translate("MainWindow", "Server IP :- ", nullptr));
        Connect_IP->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        Connect_IP->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lbl_PortNmber->setText(QCoreApplication::translate("MainWindow", "Port Number :-", nullptr));
        pbConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        Connect_pbClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Tab->setTabText(Tab->indexOf(Connect), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_Username->setText(QCoreApplication::translate("MainWindow", "User Name :-", nullptr));
        label_Password->setText(QCoreApplication::translate("MainWindow", "Password :-", nullptr));
        pb_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Login_pbClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        Tab->setTabText(Tab->indexOf(Login), QCoreApplication::translate("MainWindow", "Login", nullptr));
        lb_title_createUser->setText(QCoreApplication::translate("MainWindow", "Create User", nullptr));
        Admin_lbCreate_user_error->setText(QString());
        Admin_lbCreate_user_name->setText(QCoreApplication::translate("MainWindow", "User Name :- ", nullptr));
        Admin_lbCreate_user_pw->setText(QCoreApplication::translate("MainWindow", "Password :- ", nullptr));
        Admin_lbCreate_user_full->setText(QCoreApplication::translate("MainWindow", "Full Name :- ", nullptr));
        Admin_lbCreate_user_age->setText(QCoreApplication::translate("MainWindow", "Age :- ", nullptr));
        Admin_pbCreate_new_user->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        Admin_chkbox_CreateUser->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        lb_title_updateUser->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        Admin_lbUpdate_user_error->setText(QString());
        Admin_lbUpdate_user_acc->setText(QCoreApplication::translate("MainWindow", "Account Number :- ", nullptr));
        Admin_lbUpdate_user_name->setText(QCoreApplication::translate("MainWindow", "User Name :- ", nullptr));
        Admin_lbUpdate_user_pw->setText(QCoreApplication::translate("MainWindow", "Password :- ", nullptr));
        Admin_lbUpdate_user_full->setText(QCoreApplication::translate("MainWindow", "Full Name :- ", nullptr));
        Admin_lbUpdate_user_age->setText(QCoreApplication::translate("MainWindow", "Age :- ", nullptr));
        Admin_pbUpdate_user->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        Admin_chkbox_UpdateUser->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        lb_title_deleteUser->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        Admin_lbDelete_user_error->setText(QString());
        Admin_lbDelete_user_acc->setText(QCoreApplication::translate("MainWindow", "Account Number :- ", nullptr));
        Admin_pbDelete_user->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        Admin_lbAcc_number->setText(QString());
        Admin_lbGet_accNo_name->setText(QCoreApplication::translate("MainWindow", "User Name :- ", nullptr));
        Admin_pbGet_acc_number->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        Admin_lbView_balance->setText(QString());
        Admin_lbView_bal_acc->setText(QCoreApplication::translate("MainWindow", "Account Number :- ", nullptr));
        Admin_pbView_balance->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        lbl_title_database->setText(QCoreApplication::translate("MainWindow", "Data Base", nullptr));
        Admin_pbView_DB->setText(QCoreApplication::translate("MainWindow", "View Database", nullptr));
        Admin_lbView_DB_error->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = Admin_tbView_DB->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Account Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Admin_tbView_DB->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Authority", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Admin_tbView_DB->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Admin_tbView_DB->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Admin_tbView_DB->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Admin_tbView_DB->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        Admin_lbView_trans_history->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        Admin_pbView_trans_hist->setText(QCoreApplication::translate("MainWindow", "View Transaction history", nullptr));
        Admin_lbHistory_acc->setText(QCoreApplication::translate("MainWindow", "Account Number :- ", nullptr));
        Admin_lbHistory_count->setText(QCoreApplication::translate("MainWindow", "Count :- ", nullptr));
        Admin_leHistory_count->setText(QString());
        Admin_lbView_history_error->setText(QString());
        QTableWidgetItem *___qtablewidgetitem6 = Admin_tbView_histroy->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = Admin_tbView_histroy->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = Admin_tbView_histroy->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = Admin_tbView_histroy->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        Admin_pbLogout->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        Admin_pbExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Tab->setTabText(Tab->indexOf(Admin), QCoreApplication::translate("MainWindow", "Admin", nullptr));
        User_lbAcc_number->setText(QString());
        User_pbGet_acc_number->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        User_lbView_balance->setText(QString());
        User_pbView_balance->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        lb_title_trasfer->setText(QCoreApplication::translate("MainWindow", "Make Transfer", nullptr));
        User_lbTo_acc_number->setText(QCoreApplication::translate("MainWindow", "To Account Number :- ", nullptr));
        User_leTo_acc_number->setText(QString());
        User_lbTransfe_amout->setText(QCoreApplication::translate("MainWindow", "Transfer Amount :- ", nullptr));
        User_leTrnsfr_amount->setText(QString());
        User_lbMake_trnsf_error->setText(QString());
        User_pbMake_transfer->setText(QCoreApplication::translate("MainWindow", "Make a Transfer", nullptr));
        lb_title_trasnaction->setText(QCoreApplication::translate("MainWindow", "Make a Transaction", nullptr));
        User_lbAmount->setText(QCoreApplication::translate("MainWindow", "Amount :- ", nullptr));
        User_leTrnsct_amount->setText(QString());
        User_lbTransaction_error->setText(QString());
        User_pbMake_transaction->setText(QCoreApplication::translate("MainWindow", "Make a Transaction", nullptr));
        User_lbView_trans_history->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        User_lbHistory_count->setText(QCoreApplication::translate("MainWindow", "Count :- ", nullptr));
        User_leHistory_count->setText(QString());
        User_pbView_trans_histroy->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        User_lbView_history_error->setText(QString());
        QTableWidgetItem *___qtablewidgetitem10 = User_tbView_histroy->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = User_tbView_histroy->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = User_tbView_histroy->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = User_tbView_histroy->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        User_pbLogout->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        User_pbExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        Tab->setTabText(Tab->indexOf(User), QCoreApplication::translate("MainWindow", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
