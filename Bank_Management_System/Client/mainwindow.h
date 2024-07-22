#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QMetaEnum>
#include <QCryptographicHash>
#include <QDebug>
#include "MyClient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Slot for handling successful connection to the device
    void onConnectionDevice();
    // Slot for handling disconnection from the device
    void onDisconnectedDevice();
    // Slot for handling errors that occur with the socket
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);
    // Slot for handling changes in the socket state
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);
    // Slot for handling data received from the device
    void onReadyReadDevice(QByteArray responseData);

private slots:
    // Slot for handling the connect button click
    void on_pbConnect_clicked();
    // Slot for handling the disconnect button click
    void on_pbDisconnect_clicked();

    // Slots for user login actions
    void on_pb_login_clicked();

    // Slots for admin actions
    void on_Admin_pbCreate_new_user_clicked();
    void on_Admin_pbUpdate_user_clicked();
    void on_Admin_pbDelete_user_clicked();
    void on_Admin_pbGet_acc_number_clicked();
    void on_Admin_pbView_balance_clicked();
    void on_Admin_pbView_trans_hist_clicked();
    void on_Admin_pbView_DB_clicked();
    void on_Admin_pbLogout_clicked();
    void on_Admin_pbExit_clicked();

    // Slots for user actions
    void on_User_pbGet_acc_number_clicked();
    void on_User_pbView_balance_clicked();
    void on_User_pbMake_transfer_clicked();
    void on_User_pbMake_transaction_clicked();
    void on_User_pbView_trans_histroy_clicked();
    void on_User_pbLogout_clicked();
    void on_User_pbExit_clicked();

private:
    Ui::MainWindow *ui;
    MyClient client; // Client object for handling communication
    QString userName; // Store the username
    QString accountNumber; // Store the account number

    // Enumeration of request IDs for identifying different types of requests.
    enum requestIDs {
        LogIn_ID = 0,
        CreateUser_ID = 1,
        UpDateUser_ID = 2,
        DeleteUser_ID = 3,
        ViewBankDB_ID = 4,
        GetAccount_ID = 5,
        GetBalance_ID = 6,
        ViewTransactionHistory_ID = 7,
        MakeTransaction_ID = 8,
        TransferAmount_ID = 9
    };

    // Method to send a hashed request to the server
    void sendHashRequest(QJsonObject &requestObject);
    // Method to validate the response hash
    bool validateHashResponse(QJsonObject &responseObject);

    // Handlers for different response types
    void handleLoginResponse(const QJsonObject &responseObject);
    void handleCreateUserResponse(const QJsonObject &responseObject);
    void handleUpdateUserResponse(const QJsonObject &responseObject);
    void handleDeleteUserResponse(const QJsonObject &responseObject);
    void handleViewDataBaseResponse(const QJsonObject &responseObject);
    void handleGetAccountNumberResponse(const QJsonObject &responseObject);
    void handleViewAccountBalanceResponse(const QJsonObject &responseObject);
    void handleViewTransactionHistoryResponse(const QJsonObject &responseObject);
    void handleMakeTransactionResponse(const QJsonObject &responseObject);
    void handleTransferAmountResponse(const QJsonObject &responseObject);
};

#endif // MAINWINDOW_H
