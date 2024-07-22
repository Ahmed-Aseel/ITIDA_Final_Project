#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor for MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // Initialize the UI object
{
    ui->setupUi(this); // Setup the user interface

    // Initialize tab states
    ui->Tab->setTabEnabled(0, true);  // Enable the first tab (e.g., Login tab)
    ui->Tab->setTabEnabled(1, false); // Disable the second tab (e.g., Admin tab)
    ui->Tab->setTabEnabled(2, false); // Disable the third tab (e.g., User tab)
    ui->Tab->setTabEnabled(3, false); // Disable the fourth tab (e.g., Additional tab)

    // Connect MyClient signals to MainWindow slots
    connect(&client, &MyClient::Connection, this, &MainWindow::onConnectionDevice);
    connect(&client, &MyClient::Disconnected, this, &MainWindow::onDisconnectedDevice);
    connect(&client, &MyClient::ErrorOccurred, this, &MainWindow::onErrorOccurredDevice);
    connect(&client, &MyClient::StateChanged, this, &MainWindow::onStateChangedDevice);
    connect(&client, &MyClient::ReadyRead, this, &MainWindow::onReadyReadDevice);
}

// Destructor for MainWindow
MainWindow::~MainWindow()
{
    delete ui; // Clean up the UI object
}

// Slot called when a connection is established
void MainWindow::onConnectionDevice()
{
    QListWidgetItem *item = new QListWidgetItem("You have connected to the server....");
    item->setForeground(QBrush(QColor(Qt::green))); // Set text color to green
    ui->lw_Connect->addItem(item); // Add item to the connection log list widget

    // Update tab states for successful connection
    ui->Tab->setTabEnabled(1, true); // Enable Login tab
    ui->Tab->setCurrentIndex(1);     // Switch to Login tab
    ui->lw_Login->clear();           // Clear the login log list widget
}

// Slot called when the connection is lost
void MainWindow::onDisconnectedDevice()
{
    QListWidgetItem *item = new QListWidgetItem("You have disconnected from the server....");
    item->setForeground(QBrush(QColor(Qt::red))); // Set text color to red
    ui->lw_Connect->addItem(item); // Add item to the connection log list widget

    // Update tab states for disconnection
    ui->Tab->setTabEnabled(1, false); // Disable Login tab
    ui->Tab->setTabEnabled(2, false); // Disable Admin tab
    ui->Tab->setTabEnabled(3, false); // Disable User tab
}

// Slot called when an error occurs
void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>(); // Get the enum meta-object
    ui->lw_Connect->addItem(meta.valueToKey(socketError)); // Add the error description to the connection log list widget
}

// Slot called when the socket state changes
void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>(); // Get the enum meta-object
    ui->lw_Connect->addItem(meta.valueToKey(socketState)); // Add the state description to the connection log list widget
}

// Slot called when data is ready to be read
void MainWindow::onReadyReadDevice(QByteArray responseData)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData); // Parse the JSON response

    // Check if the response is a valid JSON object
    if (!jsonResponse.isObject())
    {
        // Invalid JSON response; no further processing
        return;
    }

    QJsonObject responseObject = jsonResponse.object(); // Extract JSON object from the response

    // Validate the response hash
    if (!(validateHashResponse(responseObject)))
    {
        return; // If hash validation fails, exit the function
    }

    qint32 responseId = responseObject["ResponseID"].toInt(); // Extract the response ID from the JSON object

    // Handle the response based on the response ID
    switch (responseId)
    {
    case LogIn_ID:
        handleLoginResponse(responseObject); // Handle login response
        break;
    case CreateUser_ID:
        handleCreateUserResponse(responseObject); // Handle create user response
        break;
    case UpDateUser_ID:
        handleUpdateUserResponse(responseObject); // Handle update user response
        break;
    case DeleteUser_ID:
        handleDeleteUserResponse(responseObject); // Handle delete user response
        break;
    case ViewBankDB_ID:
        handleViewDataBaseResponse(responseObject); // Handle view database response
        break;
    case GetAccount_ID:
        handleGetAccountNumberResponse(responseObject); // Handle get account number response
        break;
    case GetBalance_ID:
        handleViewAccountBalanceResponse(responseObject); // Handle view balance response
        break;
    case ViewTransactionHistory_ID:
        handleViewTransactionHistoryResponse(responseObject); // Handle view transaction history response
        break;
    case MakeTransaction_ID:
        handleMakeTransactionResponse(responseObject); // Handle make transaction response
        break;
    case TransferAmount_ID:
        handleTransferAmountResponse(responseObject); // Handle transfer amount response
        break;
    default:
        // Handle unknown response IDs if necessary
        break;
    }
}

/************** Responses Handlers Interfaces ***************/
void MainWindow::handleLoginResponse(const QJsonObject &responseObject)
{
    QListWidgetItem *item = new QListWidgetItem; // Create a new list widget item

    bool loginSuccess = responseObject["State"].toBool(); // Check if login was successful

    if (loginSuccess)
    {
        item->setText("You have logged in successfully."); // ShowSet success message
        item->setForeground(QBrush(QColor(Qt::green))); // Set text color to green
        ui->lw_Login->addItem(item); // Add item to the login log list widget

        ui->Login_Username->clear(); // Clear the username field
        ui->Login_Password->clear(); // Clear the password field

        userName = responseObject["UserName"].toString(); // Store the username
        accountNumber = responseObject["AccountNumber"].toString(); // Store the account number

        bool isAdmin = responseObject["IsAdmin"].toBool(); // Check if the user is an admin

        if (isAdmin)
        {
            // Enable admin tab and disable user tab
            ui->Tab->setTabEnabled(2, true); // Enable Admin tab
            ui->Tab->setTabEnabled(1, false); // Disable Login tab
            ui->Tab->setTabEnabled(3, false); // Disable User tab
            ui->Tab->setCurrentIndex(2); // Switch to Admin tab
        }
        else
        {
            // Enable user tab and disable admin tab
            ui->Tab->setTabEnabled(2, false); // Disable Admin tab
            ui->Tab->setTabEnabled(1, false); // Disable Login tab
            ui->Tab->setTabEnabled(3, true); // Enable User tab
            ui->Tab->setCurrentIndex(3); // Switch to User tab
        }
    }
    else
    {
        qint8 reason = responseObject["Reason"].toInt(); // Get the reason for login failure
        if (reason == -1)
        {
            ui->Login_Username->clear(); // Clear the username field
            item->setText("Login Failed: Invalid Username"); // Show error message
        }
        else if (reason == -2)
        {
            ui->Login_Password->clear(); // Clear the password field
            item->setText("Login Failed: Invalid Password"); // Show error message
        }
        else
        {
            item->setText("Server failed to handle this request"); // Show generic error message
        }
        item->setForeground(QBrush(QColor(Qt::red))); // Set text color to red
        ui->lw_Login->addItem(item); // Add item to the login log list widget
    }
}

void MainWindow::handleCreateUserResponse(const QJsonObject &responseObject)
{
    // Extract information from the response
    bool loginSuccess = responseObject["State"].toBool(); // Check if user creation was successful

    if (loginSuccess)
    {
        // If user creation is successful
        ui->Admin_lbCreate_user_error->setText("User Created Successfully"); // Show success message
        ui->Admin_lbCreate_user_error->setStyleSheet("QLabel { color : green; }"); // Set text color to green
        ui->Admin_leCreate_user_name->clear(); // Clear the username input field
        ui->Admin_leCreate_user_pw->clear(); // Clear the password input field
        ui->Admin_leCreate_user_full->clear(); // Clear the full name input field
        ui->Admin_leCreate_user_age->clear(); // Clear the age input field
        ui->Admin_chkbox_CreateUser->setChecked(false); // Uncheck the checkbox
    }
    else
    {
        // If user creation failed
        qint8 reason = responseObject["Reason"].toInt(); // Extract the reason for failure
        if (reason == -1)
        {
            // Username reserved
            ui->Admin_leCreate_user_name->clear(); // Clear the username input field
            ui->Admin_lbCreate_user_error->setText("Username reserved"); // Show error message
        }
        else // Reason -6 (or other unspecified reasons)
        {
            ui->Admin_lbCreate_user_error->setText("Server failed to handle this request"); // Show generic error message
        }
        ui->Admin_lbCreate_user_error->setStyleSheet("QLabel { color : red; }"); // Set text color to red
    }
}

void MainWindow::handleUpdateUserResponse(const QJsonObject &responseObject)
{
    // Extract information from the response
    bool loginSuccess = responseObject["State"].toBool(); // Check if user update was successful

    if (loginSuccess)
    {
        // If user update is successful
        ui->Admin_lbUpdate_user_error->setText("User Updated Successfully"); // Show success message
        ui->Admin_lbUpdate_user_error->setStyleSheet("QLabel { color : green; }"); // Set text color to green
        ui->Admin_leUpdate_user_acc->clear(); // Clear the account number input field
        ui->Admin_leUpdate_user_name->clear(); // Clear the username input field
        ui->Admin_leUpdate_user_pw->clear(); // Clear the password input field
        ui->Admin_leUpdate_user_full->clear(); // Clear the full name input field
        ui->Admin_leUpdate_user_age->clear(); // Clear the age input field
        ui->Admin_chkbox_UpdateUser->setChecked(false); // Uncheck the checkbox
    }
    else
    {
        // If user update failed
        qint8 reason = responseObject["Reason"].toInt(); // Extract the reason for failure
        if (reason == -1)
        {
            // Account number does not exist
            ui->Admin_leUpdate_user_acc->clear(); // Clear the account number input field
            ui->Admin_lbUpdate_user_error->setText("Account number does not exist"); // Show error message
        }
        else if (reason == -2)
        {
            // Username reserved
            ui->Admin_leUpdate_user_name->clear(); // Clear the username input field
            ui->Admin_lbUpdate_user_error->setText("Username reserved"); // Show error message
        }
        else // Reason -6 (or other unspecified reasons)
        {
            ui->Admin_lbUpdate_user_error->setText("Server failed to handle this request"); // Show generic error message
        }
        ui->Admin_lbUpdate_user_error->setStyleSheet("QLabel { color : red; }"); // Set text color to red
    }
}

void MainWindow::handleDeleteUserResponse(const QJsonObject &responseObject)
{
    // Extract information from the response
    bool loginSuccess = responseObject["State"].toBool(); // Check if user deletion was successful

    if (loginSuccess)
    {
        // If user deletion is successful
        ui->Admin_leDelete_user_acc->clear(); // Clear the account number input field
        ui->Admin_lbDelete_user_error->setText("User Deleted Successfully"); // Show success message
        ui->Admin_lbDelete_user_error->setStyleSheet("QLabel { color : green; }"); // Set text color to green
    }
    else
    {
        // If user deletion failed
        qint8 reason = responseObject["Reason"].toInt(); // Extract the reason for failure
        if (reason == -1)
        {
            // Account number does not exist
            ui->Admin_leDelete_user_acc->clear(); // Clear the account number input field
            ui->Admin_lbDelete_user_error->setText("Account number does not exist"); // Show error message
        }
        else // Reason -6 (or other unspecified reasons)
        {
            ui->Admin_lbDelete_user_error->setText("Server failed to handle this request"); // Show generic error message
        }
        ui->Admin_lbDelete_user_error->setStyleSheet("QLabel { color : red; }"); // Set text color to red
    }
}

void MainWindow::handleViewDataBaseResponse(const QJsonObject &responseObject)
{
    bool state = responseObject["State"].toBool(); // Check if database fetch was successful

    if (state)
    {
        // If database fetch is successful
        ui->Admin_lbView_DB_error->setText("Database fetched successfully"); // Show success message
        ui->Admin_lbView_DB_error->setStyleSheet("QLabel { color : green; }"); // Set text color to green

        QJsonObject DataBaseObj = responseObject.value("DataBase").toObject(); // Extract database object from response
        QStringList usersList = DataBaseObj.keys(); // Get list of usernames

        // Populate Admin_tbView_DB with user data
        int row = 0;
        for (const auto &user : usersList)
        {
            QJsonObject userObj = DataBaseObj.value(user).toObject(); // Get user object for each username
            ui->Admin_tbView_DB->insertRow(row); // Insert a new row in the table

            // Set account number
            ui->Admin_tbView_DB->setItem(row, 0, new QTableWidgetItem(userObj["AccountNumber"].toString()));

            QTableWidgetItem *item;
            if (userObj["IsAdmin"].toBool())
            {
                // If user is an admin
                item = new QTableWidgetItem("Admin");
                item->setForeground(QBrush(QColor(Qt::red)));   // Set text color to green for Admin
            }
            else
            {
                // If user is not an admin
                item = new QTableWidgetItem("User");
                item->setForeground(QBrush(QColor(Qt::blue)));    // Set text color to blue for User
            }
            // Set the item in the QTableWidget
            ui->Admin_tbView_DB->setItem(row, 1, item);

            // Set other user details
            ui->Admin_tbView_DB->setItem(row, 2, new QTableWidgetItem(user)); // Username
            ui->Admin_tbView_DB->setItem(row, 3, new QTableWidgetItem(userObj["FullName"].toString())); // Full Name
            ui->Admin_tbView_DB->setItem(row, 4, new QTableWidgetItem(userObj["Age"].toString())); // Age
            ui->Admin_tbView_DB->setItem(row, 5, new QTableWidgetItem(userObj["AccountBalance"].toString())); // Account Balance
            row++;
        }
    }
    else
    {
        // If database fetch failed
        qint8 reason = responseObject["Reason"].toInt(); // Extract the reason for failure
        if (reason == -1)
        {
            ui->Admin_lbView_DB_error->setText("Database is empty"); // Show error message
        }
        else // Reason -6 (or other unspecified reasons)
        {
            ui->Admin_lbView_DB_error->setText("Server failed to handle this request"); // Show generic error message
        }
        ui->Admin_lbView_DB_error->setStyleSheet("QLabel { color : red; }"); // Set text color to red
    }
}

void MainWindow::handleGetAccountNumberResponse(const QJsonObject &responseObject)
{
    bool state = responseObject["State"].toBool(); // Check if account number fetch was successful
    if (state)
    {
        // If account number fetch is successful
        if (ui->Admin->isEnabled())
        {
            ui->Admin_lbAcc_number->setText("Account Number: " + responseObject["AccountNumber"].toString()); // Show account number
            ui->Admin_lbAcc_number->setStyleSheet("QLabel { color : green; }"); // Set text color to green
        }
        else if (ui->User->isEnabled())
        {
            accountNumber = responseObject["AccountNumber"].toString(); // Store account number
            ui->User_lbAcc_number->setText("Account Number: " + accountNumber); // Show account number
            ui->User_lbAcc_number->setStyleSheet("QLabel { color : green; }"); // Set text color to green
        }
    }
    else
    {
        // If account number fetch failed
        qint8 reason = responseObject["Reason"].toInt(); // Extract the reason for failure

        if (ui->Admin->isEnabled())
        {
            if (reason == -1)
            {
                ui->Admin_leGet_accNo_name->clear(); // Clear the name input field
                ui->Admin_lbAcc_number->setText("User does not exist"); // Show error message
            }
            else // Reason -6 (or other unspecified reasons)
            {
                ui->Admin_lbAcc_number->setText("Server failed to handle this request"); // Show generic error message
            }
            ui->Admin_lbAcc_number->setStyleSheet("QLabel { color : red; }"); // Set text color to red
        }
        else if (ui->User->isEnabled())
        {
            if (reason == -1)
            {
                ui->User_lbAcc_number->setText("User does not exist"); // Show error message
            }
            else // Reason -6 (or other unspecified reasons)
            {
                ui->User_lbAcc_number->setText("Server failed to handle this request"); // Show generic error message
            }
            ui->User_lbAcc_number->setStyleSheet("QLabel { color : red; }"); // Set text color to red
        }
    }
}

void MainWindow::handleViewAccountBalanceResponse(const QJsonObject &responseObject)
{
    // Extract the state of the response
    bool state = responseObject["State"].toBool();

    if (state)
    {
        // If the request was successful, update the balance display
        QString balanceText = "Balance: " + responseObject["AccountBalance"].toString();

        if (ui->Admin->isEnabled())
        {
            ui->Admin_lbView_balance->setText(balanceText); // Set balance for Admin
        }
        else if (ui->User->isEnabled())
        {
            ui->User_lbView_balance->setText(balanceText); // Set balance for User
        }

        // Set text color to green indicating success
        ui->Admin_lbView_balance->setStyleSheet("QLabel { color : green; }");
        ui->User_lbView_balance->setStyleSheet("QLabel { color : green; }");
    }
    else
    {
        // If the request failed, handle errors based on the reason
        qint8 reason = responseObject["Reason"].toInt();

        if (ui->Admin->isEnabled())
        {
            if (reason == -1)
            {
                ui->Admin_leView_bal_acc->clear(); // Clear the account number input
                ui->Admin_lbView_balance->setText("Account number does not exist"); // Show error message
            }
            else
            {
                ui->Admin_lbView_balance->setText("Server failed to handle this request"); // Generic error message
            }
            ui->Admin_lbView_balance->setStyleSheet("QLabel { color : red; }");
        }
        else if (ui->User->isEnabled())
        {
            if (reason == -1)
            {
                ui->User_lbView_balance->setText("Account number does not exist"); // Show error message
            }
            else
            {
                ui->User_lbView_balance->setText("Server failed to handle this request"); // Generic error message
            }
            ui->User_lbView_balance->setStyleSheet("QLabel { color : red; }");
        }
    }
}

void MainWindow::handleViewTransactionHistoryResponse(const QJsonObject &responseObject)
{
    // Extract the state of the response
    bool state = responseObject["State"].toBool();

    if (state)
    {
        // If the request was successful, get the transaction history array
        QJsonArray transactionHistoryArray = responseObject["Transactions"].toArray();

        if (ui->Admin->isEnabled())
        {
            ui->Admin_lbView_history_error->setText("History fetched successfully"); // Success message for Admin
            ui->Admin_lbView_history_error->setStyleSheet("QLabel { color : green; }");

            // Populate Admin_tbView_histroy with transaction history data
            int row = 0;
            for (const auto &transactionDataValue : transactionHistoryArray)
            {
                QJsonObject transactionData = transactionDataValue.toObject();
                ui->Admin_tbView_histroy->insertRow(row); // Insert a new row
                ui->Admin_tbView_histroy->setItem(row, 0, new QTableWidgetItem(transactionData["Type"].toString())); // Transaction Type
                ui->Admin_tbView_histroy->setItem(row, 1, new QTableWidgetItem(transactionData["Amount"].toString())); // Transaction Amount
                ui->Admin_tbView_histroy->setItem(row, 2, new QTableWidgetItem(transactionData["Date"].toString())); // Transaction Date
                ui->Admin_tbView_histroy->setItem(row, 3, new QTableWidgetItem(transactionData["Time"].toString())); // Transaction Time
                row++;
            }
        }
        else if (ui->User->isEnabled())
        {
            ui->User_lbView_history_error->setText("History fetched successfully"); // Success message for User
            ui->User_lbView_history_error->setStyleSheet("QLabel { color : green; }");

            // Populate User_tbView_histroy with transaction history data
            int row = 0;
            for (const auto &transactionDataValue : transactionHistoryArray)
            {
                QJsonObject transactionData = transactionDataValue.toObject();
                ui->User_tbView_histroy->insertRow(row); // Insert a new row
                ui->User_tbView_histroy->setItem(row, 0, new QTableWidgetItem(transactionData["Type"].toString())); // Transaction Type
                ui->User_tbView_histroy->setItem(row, 1, new QTableWidgetItem(transactionData["Amount"].toString())); // Transaction Amount
                ui->User_tbView_histroy->setItem(row, 2, new QTableWidgetItem(transactionData["Date"].toString())); // Transaction Date
                ui->User_tbView_histroy->setItem(row, 3, new QTableWidgetItem(transactionData["Time"].toString())); // Transaction Time
                row++;
            }
        }
    }
    else
    {
        // If the request failed, handle errors based on the reason
        qint8 reason = responseObject["Reason"].toInt();

        if (ui->Admin->isEnabled())
        {
            if (reason == -1)
            {
                ui->Admin_leHistory_acc->clear(); // Clear the account number input
                ui->Admin_lbView_history_error->setText("Account number does not exist"); // Show error message
            }
            else if (reason == -2)
            {
                ui->Admin_lbView_history_error->setText("No transactions history"); // No transactions message
            }
            else
            {
                ui->Admin_lbView_history_error->setText("Server failed to handle this request"); // Generic error message
            }
            ui->Admin_lbView_history_error->setStyleSheet("QLabel { color : red; }");
        }
        else if (ui->User->isEnabled())
        {
            if (reason == -1)
            {
                ui->User_lbView_history_error->setText("Account number does not exist"); // Show error message
            }
            else if (reason == -2)
            {
                ui->User_lbView_history_error->setText("No transactions history"); // No transactions message
            }
            else
            {
                ui->User_lbView_history_error->setText("Server failed to handle this request"); // Generic error message
            }
            ui->User_lbView_history_error->setStyleSheet("QLabel { color : red; }");
        }
    }
}

void MainWindow::handleMakeTransactionResponse(const QJsonObject &responseObject)
{
    // Extract the state of the response
    bool loginSuccess = responseObject["State"].toBool();

    if (loginSuccess)
    {
        // If the transaction was successful, clear the input and show a success message
        ui->User_leTrnsct_amount->clear(); // Clear the transaction amount input
        ui->User_lbTransaction_error->setText("Transaction done Successfully"); // Success message
        ui->User_lbTransaction_error->setStyleSheet("QLabel { color : green; }");
    }
    else
    {
        // If the transaction failed, handle errors based on the reason
        qint8 reason = responseObject["Reason"].toInt();
        if (reason == -1)
        {
            ui->User_lbTransaction_error->setText("Account number does not exist"); // Show error message
        }
        else if (reason == -2)
        {
            ui->User_leTrnsct_amount->clear(); // Clear the transaction amount input
            ui->User_lbTransaction_error->setText("Your balance is not sufficient"); // Insufficient balance message
        }
        else
        {
            ui->User_lbTransaction_error->setText("Server failed to handle this request"); // Generic error message
        }
        ui->User_lbTransaction_error->setStyleSheet("QLabel { color : red; }");
    }
}

void MainWindow::handleTransferAmountResponse(const QJsonObject &responseObject)
{
    // Extract the state of the response
    bool loginSuccess = responseObject["State"].toBool();

    if (loginSuccess)
    {
        // If the transfer was successful, clear the input and show a success message
        ui->User_leTrnsfr_amount->clear(); // Clear the transfer amount input
        ui->User_lbMake_trnsf_error->setText("Transfer done Successfully"); // Success message
        ui->User_lbMake_trnsf_error->setStyleSheet("QLabel { color : green; }");
    }
    else
    {
        // If the transfer failed, handle errors based on the reason
        qint8 reason = responseObject["Reason"].toInt();
        if (reason == -1)
        {
            ui->User_lbMake_trnsf_error->setText("Account number does not exist"); // Show error message
        }
        else if (reason == -2)
        {
            ui->User_leTrnsfr_amount->clear(); // Clear the transfer amount input
            ui->User_lbMake_trnsf_error->setText("Balance is not sufficient"); // Insufficient balance message
        }
        else
        {
            ui->User_lbMake_trnsf_error->setText("Server failed to handle this request"); // Generic error message
        }
        ui->User_lbMake_trnsf_error->setStyleSheet("QLabel { color : red; }");
    }
}

/************** Hashing APIs Interfaces ***************/
// Function to send a JSON request to the server with an appended SHA-256 hash for data integrity
void MainWindow::sendHashRequest(QJsonObject &requestObject)
{
    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);

    // Create a cryptographic hash object with SHA-256 algorithm
    QCryptographicHash hashedRequest(QCryptographicHash::Sha256);

    // Hash the JSON request
    hashedRequest.addData(requestDoc.toJson());

    // Include the hash in the JSON request before sending
    requestObject["Hash"] = QString((hashedRequest.result()).toHex());

    // Update the JSON document with the hash
    QJsonDocument updatedRequestDoc(requestObject);

    // Send the request to the server
    client.WriteData(updatedRequestDoc.toJson());
}

// Function to validate the hash in the response to ensure data integrity
bool MainWindow::validateHashResponse(QJsonObject &responseObject)
{
    // Extract the hash from the JSON response
    QString receivedHashHex = responseObject.value("Hash").toString();
    QByteArray receivedHash = QByteArray::fromHex(receivedHashHex.toUtf8());

    // Remove the hash field from the response for hashing the rest of the data
    responseObject.remove("Hash");
    QJsonDocument responseWithoutHash(responseObject);

    // Compute the hash of the response without the hash field
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(responseWithoutHash.toJson());
    QByteArray computedHash = hash.result();

    // Compare the computed hash with the received hash to verify integrity
    if (computedHash == receivedHash)
    {
        // The response is verified and integrity is intact
        return true;
    }
    else
    {
        // The response verification failed; integrity is compromised
        return false;
    }
}

/************** Connect APIs Interfaces ***************/
// Slot for handling the "Connect" button click
void MainWindow::on_pbConnect_clicked()
{
    // Retrieve IP address and port from the UI
    QString ip = ui->Connect_IP->text();
    qint32 port = ui->Connect_Port->text().toInt();

    // Connect to the device using the provided IP address and port
    client.ConnectToDevice(ip, port);
}

// Slot for handling the "Disconnect" button click
void MainWindow::on_pbDisconnect_clicked()
{
    // Disconnect from the device
    client.Disconnect();
}

/************** Login APIs Interfaces ***************/
// Slot for handling the "Login" button click
void MainWindow::on_pb_login_clicked()
{
    // Create a new list widget item for displaying status messages
    QListWidgetItem *item = new QListWidgetItem;

    // Retrieve username and password from the UI
    QString username = ui->Login_Username->text();
    QString password = ui->Login_Password->text();

    // Validate that both fields are filled in
    if (username.isEmpty() || password.isEmpty())
    {
        item->setText("Warning: Please fill in the username and password.");
        item->setForeground(QBrush(QColor(Qt::red)));
        ui->lw_Login->addItem(item); // Add warning message to the list widget
        return;
    }

    item->setText("Validating your username and password...");
    item->setForeground(QBrush(QColor(Qt::blue)));
    ui->lw_Login->addItem(item); // Add status message to the list widget

    // Construct the request JSON object for login
    QJsonObject requestObject;
    requestObject["RequestID"] = LogIn_ID;
    requestObject["UserName"] = username;
    requestObject["Password"] = password;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

/************** Admin APIs Interfaces ***************/
// Slot for handling the "Create New User" button click
void MainWindow::on_Admin_pbCreate_new_user_clicked()
{
    // Clear any previous error messages
    ui->Admin_lbCreate_user_error->clear();

    // Retrieve user details from the UI
    QString UserName = ui->Admin_leCreate_user_name->text();
    QString Password = ui->Admin_leCreate_user_pw->text();
    QString FullName = ui->Admin_leCreate_user_full->text();
    quint8 Age = ui->Admin_leCreate_user_age->text().toUInt();
    bool IsAdmin = ui->Admin_chkbox_CreateUser->isChecked();

    // Validate that all required fields are filled in
    if (UserName.isEmpty() || Password.isEmpty() || FullName.isEmpty())
    {
        ui->Admin_lbCreate_user_error->setText("All fields are required");
        ui->Admin_lbCreate_user_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Validate the age
    if ((Age < 18) || (Age > 100))
    {
        ui->Admin_leCreate_user_age->clear();
        ui->Admin_lbCreate_user_error->setText("Age must be between 18 and 100");
        ui->Admin_lbCreate_user_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for creating a new user
    QJsonObject requestObject;
    requestObject["RequestID"] = CreateUser_ID;
    requestObject["UserName"] = UserName;
    requestObject["Password"] = Password;
    requestObject["FullName"] = FullName;
    requestObject["Age"] = QString::number(Age);
    requestObject["IsAdmin"] = IsAdmin;
    requestObject["AccountBalance"] = "0"; // Default balance

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Update User" button click
void MainWindow::on_Admin_pbUpdate_user_clicked()
{
    // Clear any previous error messages
    ui->Admin_lbUpdate_user_error->clear();

    // Retrieve user details from the UI
    QString AccountNumber = ui->Admin_leUpdate_user_acc->text();
    QString Age = ui->Admin_leUpdate_user_age->text();

    // Validate that the account number is provided
    if (AccountNumber.isEmpty())
    {
        ui->Admin_lbUpdate_user_error->setText("Account number is required");
        ui->Admin_lbUpdate_user_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Validate the age if provided
    if (!(Age.isEmpty()) && (Age.toUInt() < 18 || Age.toUInt() > 100))
    {
        ui->Admin_leUpdate_user_age->clear();
        ui->Admin_lbUpdate_user_error->setText("Age must be between 18 and 100");
        ui->Admin_lbUpdate_user_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for updating a user
    QJsonObject requestObject;
    requestObject["RequestID"] = UpDateUser_ID;
    requestObject["AccountNumber"] = AccountNumber;
    requestObject["UserName"] = ui->Admin_leUpdate_user_name->text();
    requestObject["Password"] = ui->Admin_leUpdate_user_pw->text();
    requestObject["FullName"] = ui->Admin_leUpdate_user_full->text();
    requestObject["Age"] = Age;
    requestObject["IsAdmin"] = ui->Admin_chkbox_UpdateUser->isChecked();

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Delete User" button click
void MainWindow::on_Admin_pbDelete_user_clicked()
{
    // Clear any previous error messages
    ui->Admin_lbDelete_user_error->clear();

    // Retrieve the account number from the UI
    QString AccountNumber = ui->Admin_leDelete_user_acc->text();

    // Validate that the account number is provided
    if (AccountNumber.isEmpty())
    {
        ui->Admin_lbDelete_user_error->setText("Account number is required");
        ui->Admin_lbDelete_user_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for deleting a user
    QJsonObject requestObject;
    requestObject["RequestID"] = DeleteUser_ID;
    requestObject["AccountNumber"] = AccountNumber;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Get Account Number" button click
void MainWindow::on_Admin_pbGet_acc_number_clicked()
{
    // Clear any previous error messages
    ui->Admin_lbAcc_number->clear();

    // Retrieve the username from the UI
    QString UserName = ui->Admin_leGet_accNo_name->text();

    // Validate that the username is provided
    if (UserName.isEmpty())
    {
        ui->Admin_lbAcc_number->setText("Username is required");
        ui->Admin_lbAcc_number->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for getting an account number
    QJsonObject requestObject;
    requestObject["RequestID"] = GetAccount_ID;
    requestObject["UserName"] = UserName;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

/************** Admin APIs Interfaces ***************/
// Slot for handling the "View Balance" button click
void MainWindow::on_Admin_pbView_balance_clicked()
{
    // Clear any previous balance display
    ui->Admin_lbView_balance->clear();

    // Retrieve the account number from the UI
    QString AccountNumber = ui->Admin_leView_bal_acc->text();

    // Validate that the account number is provided
    if (AccountNumber.isEmpty())
    {
        ui->Admin_lbView_balance->setText("Account number is required");
        ui->Admin_lbView_balance->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for viewing balance
    QJsonObject requestObject;
    requestObject["RequestID"] = GetBalance_ID;
    requestObject["AccountNumber"] = AccountNumber;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "View Transaction History" button click
void MainWindow::on_Admin_pbView_trans_hist_clicked()
{
    // Clear any previous error messages and table contents
    ui->Admin_lbView_history_error->clear();
    ui->Admin_tbView_histroy->clearContents();
    ui->Admin_tbView_histroy->setRowCount(0);

    // Retrieve account number and count from the UI
    QString AccountNumber = ui->Admin_leHistory_acc->text();
    QString Count = ui->Admin_leHistory_count->text();

    // Validate that both fields are filled in and the count is valid
    if (AccountNumber.isEmpty() || Count.isEmpty())
    {
        ui->Admin_lbView_history_error->setText("All fields are required");
        ui->Admin_lbView_history_error->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if (Count.toInt() <= 0)
    {
        ui->Admin_leHistory_count->clear();
        ui->Admin_lbView_history_error->setText("Count must be greater than 0");
        ui->Admin_lbView_history_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for viewing transaction history
    QJsonObject requestObject;
    requestObject["RequestID"] = ViewTransactionHistory_ID;
    requestObject["AccountNumber"] = AccountNumber;
    requestObject["Count"] = Count;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "View Database" button click
void MainWindow::on_Admin_pbView_DB_clicked()
{
    // Clear any previous error messages and table contents
    ui->Admin_lbView_DB_error->clear();
    ui->Admin_tbView_DB->clearContents();
    ui->Admin_tbView_DB->setRowCount(0);

    // Construct the request JSON object for viewing the database
    QJsonObject requestObject;
    requestObject["RequestID"] = ViewBankDB_ID;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Logout" button click
void MainWindow::on_Admin_pbLogout_clicked()
{
    // Switch back to the login tab and disable other tabs
    ui->Tab->setTabEnabled(1, true);
    ui->Tab->setTabEnabled(2, false);
    ui->Tab->setCurrentIndex(1);

    // Display a logout message
    QListWidgetItem *item = new QListWidgetItem("You have logged out");
    item->setForeground(QBrush(QColor(Qt::red)));
    ui->lw_Login->addItem(item);
}

// Slot for handling the "Exit" button click
void MainWindow::on_Admin_pbExit_clicked()
{
    // Disconnect from the device and quit the application
    client.Disconnect();
    QApplication::quit();
}

/************** User APIs Interfaces ***************/
// Slot for handling the "Get Account Number" button click
void MainWindow::on_User_pbGet_acc_number_clicked()
{
    // Clear any previous account number display
    ui->User_lbAcc_number->clear();

    // Construct the request JSON object for getting the account number
    QJsonObject requestObject;
    requestObject["RequestID"] = GetAccount_ID;
    requestObject["UserName"] = userName; // Assuming `userName` is a member variable

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "View Balance" button click
void MainWindow::on_User_pbView_balance_clicked()
{
    // Clear any previous balance display
    ui->User_lbView_balance->clear();

    // Construct the request JSON object for viewing balance
    QJsonObject requestObject;
    requestObject["RequestID"] = GetBalance_ID;
    requestObject["AccountNumber"] = accountNumber; // Assuming `accountNumber` is a member variable

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Make Transfer" button click
void MainWindow::on_User_pbMake_transfer_clicked()
{
    // Clear any previous error messages
    ui->User_lbMake_trnsf_error->clear();

    // Retrieve receiver account number and amount from the UI
    QString ReceiverAccountNumber = ui->User_leTo_acc_number->text();
    QString Amount = ui->User_leTrnsfr_amount->text();

    // Validate that all fields are filled in and the amount is valid
    if ((ReceiverAccountNumber.isEmpty()) || (Amount.isEmpty()))
    {
        ui->User_lbMake_trnsf_error->setText("All fields are required");
        ui->User_lbMake_trnsf_error->setStyleSheet("QLabel { color : red; }");
        return;
    }
    if (Amount.toInt() == 0)
    {
        ui->User_leTrnsfr_amount->clear();
        ui->User_lbMake_trnsf_error->setText("Amount is required and cannot be 0");
        ui->User_lbMake_trnsf_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for making a transfer
    QJsonObject requestObject;
    requestObject["RequestID"] = TransferAmount_ID;
    requestObject["SenderAccountNumber"] = accountNumber;
    requestObject["ReceiverAccountNumber"] = ReceiverAccountNumber;
    requestObject["Amount"] = Amount;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Make Transaction" button click
void MainWindow::on_User_pbMake_transaction_clicked()
{
    // Clear any previous error messages
    ui->User_lbTransaction_error->clear();

    // Retrieve amount from the UI
    QString Amount = ui->User_leTrnsct_amount->text();

    // Validate that the amount is provided and not zero
    if ((Amount.isEmpty()) || (Amount.toInt() == 0))
    {
        ui->User_leTrnsct_amount->clear();
        ui->User_lbTransaction_error->setText("Amount is required and cannot be 0");
        ui->User_lbTransaction_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for making a transaction
    QJsonObject requestObject;
    requestObject["RequestID"] = MakeTransaction_ID;
    requestObject["AccountNumber"] = accountNumber;
    requestObject["Amount"] = Amount;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "View Transaction History" button click
void MainWindow::on_User_pbView_trans_histroy_clicked()
{
    // Clear any previous error messages and table contents
    ui->User_lbView_history_error->clear();
    ui->User_tbView_histroy->clearContents();
    ui->User_tbView_histroy->setRowCount(0);

    // Retrieve count from the UI
    QString Count = ui->User_leHistory_count->text();

    // Validate that the count is provided and greater than 0
    if ((Count.isEmpty()) || (Count.toInt() <= 0))
    {
        ui->User_leHistory_count->clear();
        ui->User_lbView_history_error->setText("Count must be greater than 0");
        ui->User_lbView_history_error->setStyleSheet("QLabel { color : red; }");
        return;
    }

    // Construct the request JSON object for viewing transaction history
    QJsonObject requestObject;
    requestObject["RequestID"] = ViewTransactionHistory_ID;
    requestObject["AccountNumber"] = accountNumber;
    requestObject["Count"] = Count;

    // Send the request with hashed data
    sendHashRequest(requestObject);
}

// Slot for handling the "Logout" button click
void MainWindow::on_User_pbLogout_clicked()
{
    // Switch back to the login tab and disable other tabs
    ui->Tab->setTabEnabled(1, true);
    ui->Tab->setTabEnabled(3, false);
    ui->Tab->setCurrentIndex(1);

    // Display a logout message
    QListWidgetItem *item = new QListWidgetItem("You have logged out");
    item->setForeground(QBrush(QColor(Qt::red)));
    ui->lw_Login->addItem(item);
}

// Slot for handling the "Exit" button click
void MainWindow::on_User_pbExit_clicked()
{
    // Disconnect from the device and quit the application
    client.Disconnect();
    QApplication::quit();
}
