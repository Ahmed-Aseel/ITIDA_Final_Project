#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QJsonDocument>      // Includes the QJsonDocument class for handling JSON documents
#include <QJsonObject>        // Includes the QJsonObject class for handling JSON objects
#include <QJsonArray>         // Includes the QJsonArray class for handling JSON arrays
#include <QJsonValue>         // Includes the QJsonValue class for handling JSON values
#include <QCryptographicHash> // Includes the QCryptographicHash class for hashing operations
#include <QMutex>             // Includes the QMutex class for thread synchronization
#include <memory>             // Includes smart pointers such as std::unique_ptr
#include <QDebug>             // Includes the QDebug class for logging and debugging
#include "DataBaseHandler.h"  // Includes the header file for handling database operations
#include "Logger.h"

// The RequestHandler class is responsible for processing client requests and interacting with the database.
// It handles various types of requests, validates them, and generates appropriate responses.
class RequestHandler
{
public:
    // Constructor to initialize the RequestHandler object.
    RequestHandler();
    ~RequestHandler();

    // Method to handle a request from the client.
    // The request is provided as a QByteArray, and the method returns a QByteArray response.
    QByteArray handleReaquest(const QByteArray &request);

private:
    std::shared_ptr<DataBaseHandler> db_handler; // Shared pointer to the DataBaseHandler instance used for database operations
    static QMutex globalMutex;   // Static mutex for synchronizing access to shared resources across instances
    Logger *RequestLogs;

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

    // Method to validate the hash in the request object.
    // Returns true if the hash is valid, otherwise false.
    bool validateHashRequest(QJsonObject &requestObject);

    // Method to generate a hash for the response object.
    void hashResponse(QJsonObject &responseObject);
};

#endif // REQUESTHANDLER_H
