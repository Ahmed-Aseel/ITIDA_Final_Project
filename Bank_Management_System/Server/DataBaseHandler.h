#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QTextStream>       // Includes the QTextStream class for text stream operations
#include <QByteArray>        // Includes the QByteArray class for handling byte arrays
#include <QJsonDocument>     // Includes the QJsonDocument class for handling JSON documents
#include <QJsonObject>       // Includes the QJsonObject class for handling JSON objects
#include <QJsonArray>        // Includes the QJsonArray class for handling JSON arrays
#include <QJsonParseError>   // Includes the QJsonParseError class for handling JSON parse errors
#include <QFile>             // Includes the QFile class for file handling
#include <QRandomGenerator>  // Includes the QRandomGenerator class for random number generation
#include <memory>            // Includes smart pointers such as std::unique_ptr
#include <QDebug>            // Includes the QDebug class for logging and debugging
#include "Logger.h"

// The DataBaseHandler class is responsible for managing database operations, including user authentication,
// user creation, user updates, user deletion, and handling various database queries.
class DataBaseHandler
{
private:
    // Constructor to initialize the DataBaseHandler object.
    DataBaseHandler();

    // Method to initialize the database.
    void initilaize();

    // Method to check the integrity of the database.
    bool CheckDataBase(QJsonObject &jResponse, QJsonParseError &jError, QJsonDocument &doc);

    // Smart pointer to manage the QFile instance for the database file.
    std::unique_ptr<QFile> DataBaseFile;

    // Instance of QRandomGenerator for generating random numbers.
    QRandomGenerator randomNumGen;

    // Static variable for user ID generation.
    // static qint16 userID;

public:
    // Destructor to clean up resources.
    ~DataBaseHandler();

    // Method to get the singleton instance of DataBaseHandler.
    static std::shared_ptr<DataBaseHandler> getInstance();

    // Delete the copy constructor to prevent copying.
    DataBaseHandler(const DataBaseHandler&) = delete;

    // Delete the assignment operator to prevent assignment.
    DataBaseHandler& operator=(const DataBaseHandler&) = delete;

    // Methods for handling various database operations.
    QJsonObject logIn(const QJsonObject &data);
    QJsonObject createUser(QJsonObject &data);
    QJsonObject updateUser(const QJsonObject &data);
    QJsonObject deleteUser(const QJsonObject &data);
    QJsonObject viewBankDB();
    QJsonObject getAccount_Number(const QJsonObject &data);
    QJsonObject viewAccount_Balance(const QJsonObject &data);
    QJsonObject viewTransaction_History(const QJsonObject &data);
    QJsonObject makeTransaction(const QJsonObject &data);
    QJsonObject transferAmount(const QJsonObject &data);

    Logger *DBLogs;
};

#endif // DATABASEHANDLER_H
