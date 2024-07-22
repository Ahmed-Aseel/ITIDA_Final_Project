#include "DataBaseHandler.h"

// Constructor: Initializes the database file and populates it if it doesn't exist
DataBaseHandler::DataBaseHandler()
{
    DataBaseFile = std::make_unique<QFile>("BankDataBase.json");
    DBLogs = new Logger("Logs/DBLogs.txt");
    initilaize(); // Set up the initial database state if the file does not exist
}

// Destructor: Default destructor
DataBaseHandler::~DataBaseHandler()
{
    DBLogs->log("Destroying the DataBaseHandler object along with its resources");
    delete DBLogs;
}

// Initializes the database file with default values if it does not already exist
void DataBaseHandler::initilaize()
{
    // Check if the database file exists
    if (!DataBaseFile->exists())
    {
        // Open the database file for writing
        DataBaseFile->open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(DataBaseFile.get());

        // Prepare default user data
        QJsonObject admin1, user1;
        QJsonArray history; // Transaction history is initialized as an empty array
        QJsonObject container;
        QJsonDocument doc;

        // Admin user data
        admin1["FullName"] = "Ahmed Aseel";
        admin1["AccountNumber"] = "100";
        admin1["Age"] = "24";
        admin1["Password"] = "252000";
        admin1["IsAdmin"] = true;
        admin1["AccountBalance"] = "0";
        admin1["TransactionHistory"] = history;
        container["Ahmed25"] = admin1;

        // Regular user data
        user1["FullName"] = "Shimaa Aseel";
        user1["AccountNumber"] = "200";
        user1["Age"] = "26";
        user1["Password"] = "891998";
        user1["IsAdmin"] = false;
        user1["AccountBalance"] = "0";
        user1["TransactionHistory"] = history;
        container["Shimaa98"] = user1;

        // Set the container as the document's root object
        doc.setObject(container);
        stream << QString::fromUtf8(doc.toJson(QJsonDocument::Indented));
        stream.flush(); // Ensure all data is written to the file
        DataBaseFile->close(); // Close the file after writing
    }
}

// Static method to get the singleton instance of DataBaseHandler
std::shared_ptr<DataBaseHandler> DataBaseHandler::getInstance()
{
    static std::shared_ptr<DataBaseHandler> instance(new DataBaseHandler());
    return instance;
}

// Checks if the database file exists and is readable, and parses it into a QJsonDocument
bool DataBaseHandler::CheckDataBase(QJsonObject &jResponse, QJsonParseError &jError, QJsonDocument &doc)
{
    // Check if the database file exists
    if (!DataBaseFile->exists())
    {
        DBLogs->log("Database file doesn't exist.");
        jResponse["State"] = false;
        jResponse["Reason"] = -5; // File does not exist
        return false;
    }

    // Open the database file for reading
    if (!DataBaseFile->open(QIODevice::ReadOnly))
    {
        DBLogs->log("Failed to open database file for reading.");
        DataBaseFile->close(); // Close the file if opening fails
        jResponse["State"] = false;
        jResponse["Reason"] = -4; // Failed to open file for reading
        return false;
    }

    // Read and parse the JSON data from the file
    doc = QJsonDocument::fromJson(DataBaseFile->readAll(), &jError);
    DataBaseFile->close(); // Close the file after reading

    // Check for parsing errors
    if (jError.error != QJsonParseError::NoError)
    {
        DBLogs->log("Failed to parse JSON.");
        jResponse["State"] = false;
        jResponse["Reason"] = -3; // Failed to parse JSON
        return false;
    }

    return true; // Successfully checked and parsed the database
}

// Handles user login by checking credentials against the database
QJsonObject DataBaseHandler::logIn(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;
    QJsonObject obj;

    // Verify the database file and parse it
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    obj = doc.object(); // Convert QJsonDocument to QJsonObject

    // Check if the user exists in the database
    if (!obj.contains(data.value("UserName").toString()))
    {
        DBLogs->log("Incorrect Username.");
        jResponse["State"] = false;
        jResponse["Reason"] = -1; // User not found
        return jResponse;
    }

    // Validate the provided password
    QString userPass = obj.value(data.value("UserName").toString()).toObject().value("Password").toString();
    if (data.value("Password").toString() != userPass)
    {
        DBLogs->log("Incorrect Password.");
        jResponse["State"] = false;
        jResponse["Reason"] = -2; // Incorrect password
        return jResponse;
    }

    // If login is successful, return user details
    bool isAdmin = obj.value(data.value("UserName").toString()).toObject().value("IsAdmin").toBool();
    QString accountNumber = obj.value(data.value("UserName").toString()).toObject().value("AccountNumber").toString();

    jResponse["State"] = true;
    jResponse["IsAdmin"] = isAdmin;
    jResponse["UserName"] = data.value("UserName").toString();
    jResponse["AccountNumber"] = accountNumber;

    DBLogs->log("User: " + data.value("UserName").toString() + " has logged in successfully.");

    return jResponse; // Return successful login response
}

// Creates a new user in the database
QJsonObject DataBaseHandler::createUser(QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Verify the database file and parse it
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject jsonObj = doc.object(); // Convert QJsonDocument to QJsonObject

    // Check if the username is already taken
    if (jsonObj.contains(data.value("UserName").toString()))
    {
        DBLogs->log("Username already taken.");
        jResponse["State"] = false;
        jResponse["Reason"] = -1; // Username already taken
        return jResponse;
    }

    // Generate a unique account number
    bool flag;
    qint32 accountNum;
    QStringList list = jsonObj.keys();

    while (true)
    {
        accountNum = randomNumGen.bounded(1, 1000); // Generate a random account number
        flag = false;
        for (const QString &key : list)
        {
            qint32 number = jsonObj.value(key).toObject().value("AccountNumber").toString().toInt();
            if (number == accountNum)
            {
                flag = true; // Account number already exists
                break;
            }
        }
        if (!flag)
        {
            break; // Unique account number found
        }
    }

    // Prepare new user data
    QJsonArray history; // Transaction history initialized as an empty array
    data["TransactionHistory"] = history;
    data["AccountNumber"] = QString::number(accountNum);

    // Insert new user data into the JSON object
    data.remove("RequestID"); // Remove request ID from user data
    QJsonObject newobj = data;
    newobj.remove("UserName"); // Remove username from the user object before adding
    jsonObj.insert(data.value("UserName").toString(), newobj);

    // Open the database file for writing and update it
    if (!DataBaseFile->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        DBLogs->log("Failed to open file for writing.");
        jResponse["State"] = false;
        jResponse["Reason"] = -4; // Failed to open file for writing
        return jResponse;
    }

    // Write the updated JSON to the file
    QJsonDocument writableDoc(jsonObj);
    QTextStream stream(DataBaseFile.get());
    stream << QString::fromUtf8(writableDoc.toJson(QJsonDocument::Indented));
    DataBaseFile->close(); // Close the file after writing

    DBLogs->log("User: " + data.value("UserName").toString() + " created successfully.");
    jResponse["State"] = true; // Indicate successful user creation
    return jResponse;
}

// Updates an existing user's information in the database
QJsonObject DataBaseHandler::updateUser(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject jsonObj = doc.object(); // Get the JSON object from the document
    QStringList list = jsonObj.keys(); // Get all keys (usernames) from the JSON object
    QString desiredKey;
    bool flag = false;

    // Search for the user with the specified account number
    foreach (QString key, list)
    {
        QString number = jsonObj.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("AccountNumber").toString())
        {
            desiredKey = key;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        // User found, proceed with updating
        QJsonObject desiredObj = jsonObj.value(desiredKey).toObject();
        desiredObj["IsAdmin"] = data.value("IsAdmin").toBool(); // Update admin status

        // Update other fields if provided
        if (!data.value("FullName").toString().isEmpty())
        {
            desiredObj["FullName"] = data.value("FullName").toString();
        }
        if (!data.value("Password").toString().isEmpty())
        {
            desiredObj["Password"] = data.value("Password").toString();
        }
        if (!data.value("Age").toString().isEmpty())
        {
            desiredObj["Age"] = data.value("Age").toString();
        }
        if (!data.value("UserName").toString().isEmpty())
        {
            // Check if the new username is already taken
            if (!jsonObj.contains(data.value("UserName").toString()))
            {
                jsonObj[data.value("UserName").toString()] = desiredObj; // Update the username
                jsonObj.remove(desiredKey); // Remove old username
            }
            else
            {
                DBLogs->log("User: " + data.value("UserName").toString() + " already exists.");
                jResponse["State"] = false;
                jResponse["Reason"] = -2; // New username already exists
                return jResponse;
            }
        }
        else
        {
            // Just update the existing username
            jsonObj.remove(desiredKey);
            jsonObj[desiredKey] = desiredObj;
        }

        // Write the modified JSON object back to the file
        if (!DataBaseFile->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            DBLogs->log("Failed to open file for reading and writing.");
            jResponse["State"] = false;
            jResponse["Reason"] = -4; // Failed to open file for reading and writing
            DataBaseFile->close();
            return jResponse;
        }

        DataBaseFile->resize(0); // Clear existing content
        QTextStream stream(DataBaseFile.get());
        stream << QJsonDocument(jsonObj).toJson(QJsonDocument::Indented);
        DataBaseFile->close(); // Close the file after writing

        DBLogs->log("User: " + data.value("AccountNumber").toString() + " updated successfully.");
        jResponse["State"] = true; // Indicate successful update
        return jResponse;
    }

    // User not found
    DBLogs->log("User: " + data.value("AccountNumber").toString() + " not found.");
    jResponse["State"] = false;
    jResponse["Reason"] = -1; // User not found in database
    return jResponse;
}

// Deletes a user from the database
QJsonObject DataBaseHandler::deleteUser(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject jsonObj = doc.object(); // Get the JSON object from the document
    QStringList list = jsonObj.keys(); // Get all keys (usernames) from the JSON object
    bool flag = false;

    // Search for the user with the specified account number
    foreach (QString key, list)
    {
        QString number = jsonObj.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("AccountNumber").toString())
        {
            jsonObj.remove(key); // Remove the user
            flag = true;
            break;
        }
    }

    if (flag)
    {
        // Write the modified JSON object back to the file
        if (!DataBaseFile->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            DBLogs->log("Failed to open file for reading and writing.");
            jResponse["State"] = false;
            jResponse["Reason"] = -4; // Failed to open file for reading and writing
            DataBaseFile->close();
            return jResponse;
        }

        DataBaseFile->resize(0); // Clear existing content
        QTextStream stream(DataBaseFile.get());
        stream << QJsonDocument(jsonObj).toJson(QJsonDocument::Indented);
        DataBaseFile->close(); // Close the file after writing

        DBLogs->log("User: " + data.value("AccountNumber").toString() + " deleted successfully.");
        jResponse["State"] = true; // Indicate successful deletion
        return jResponse;
    }

    // User not found
    DBLogs->log("User: " + data.value("AccountNumber").toString() + " not found.");
    jResponse["State"] = false;
    jResponse["Reason"] = -1; // User not found in database
    return jResponse;
}

// Retrieves the entire database
QJsonObject DataBaseHandler::viewBankDB()
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject obj = doc.object(); // Get the JSON object from the document

    // Check if the database is empty
    if (obj.isEmpty())
    {
        DBLogs->log("Database is empty.");
        jResponse["State"] = false;
        jResponse["Reason"] = -1; // Database is empty
        return jResponse;
    }

    // Return the database content
    DBLogs->log("Return the database content.");
    jResponse["DataBase"] = obj;
    jResponse["State"] = true; // Indicate successful retrieval
    return jResponse;
}

// Retrieves the account number associated with a given username
QJsonObject DataBaseHandler::getAccount_Number(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject obj = doc.object(); // Get the JSON object from the document

    // Check if the user exists in the database
    if (obj.value(data.value("UserName").toString()) == QJsonValue::Undefined)
    {
        DBLogs->log("User: " + data.value("UserName").toString() + " not found.");
        jResponse["State"] = false;
        jResponse["Reason"] = -1; // User not found
        return jResponse;
    }

    // Retrieve the account number of the user
    QString accountNumber = obj.value(data.value("UserName").toString()).toObject().value("AccountNumber").toString();

    DBLogs->log("Return account number of the user.");
    jResponse["State"] = true;
    jResponse["AccountNumber"] = accountNumber;
    return jResponse;
}

// Retrieves the balance of a given account number
QJsonObject DataBaseHandler::viewAccount_Balance(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject database = doc.object(); // Get the JSON object from the document
    QJsonObject desiredObj;
    QStringList list = database.keys(); // Get all keys (usernames) from the JSON object
    bool flag = false;

    // Search for the account number
    foreach (QString key, list)
    {
        QString number = database.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("AccountNumber").toString())
        {
            desiredObj = database.value(key).toObject(); // Retrieve the account details
            flag = true;
            break;
        }
    }

    // User found
    if (flag)
    {
        jResponse["AccountBalance"] = desiredObj.value("AccountBalance"); // Retrieve and return the balance
        DBLogs->log("Return balance of the user.");
        jResponse["State"] = true;
        return jResponse;
    }

    // User not found
    DBLogs->log("User: " + data.value("AccountNumber").toString() + " not found.");
    jResponse["State"] = false;
    jResponse["Reason"] = -1; // Account number not found
    return jResponse;
}

// Retrieves the transaction history for a given account number
QJsonObject DataBaseHandler::viewTransaction_History(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject database = doc.object(); // Get the JSON object from the document
    QJsonObject desiredObj;
    QJsonArray newArr;
    int count = data.value("Count").toString().toInt(); // Number of transactions to retrieve
    QStringList list = database.keys(); // Get all keys (usernames) from the JSON object
    bool flag = false;

    // Search for the account number
    foreach (QString key, list)
    {
        QString number = database.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("AccountNumber").toString())
        {
            desiredObj = database.value(key).toObject(); // Retrieve the account details
            flag = true;
            break;
        }
    }

    // User found
    if (flag)
    {
        QJsonArray transHistory = desiredObj.value("TransactionHistory").toArray(); // Retrieve transaction history
        if (transHistory.isEmpty())
        {
            DBLogs->log("No transactions history of the user found.");
            jResponse["State"] = false;
            jResponse["Reason"] = -2; // No transactions found
            return jResponse;
        }

        // Retrieve the most recent transactions up to the specified count
        for (int i = transHistory.size() - 1; i >= 0; i--)
        {
            newArr.append(transHistory.at(i).toObject());
            count--;
            if (count == 0)
            {
                break;
            }
        }

        DBLogs->log("Return transactions history of the user.");
        jResponse["Transactions"] = newArr;
        jResponse["State"] = true;
        return jResponse;
    }

    // User not found
    DBLogs->log("User: " + data.value("AccountNumber").toString() + " not found.");
    jResponse["State"] = false;
    jResponse["Reason"] = -1; // Account number not found
    return jResponse;
}

// Performs a transaction (deposit or withdrawal) on a given account
QJsonObject DataBaseHandler::makeTransaction(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject desiredObj;
    QString desiredKey;
    QJsonObject database = doc.object(); // Get the JSON object from the document
    QStringList list = database.keys(); // Get all keys (usernames) from the JSON object
    bool flag = false;

    // Search for the account number
    foreach (QString key, list)
    {
        QString number = database.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("AccountNumber").toString())
        {
            desiredKey = key; // Save the key for updating
            desiredObj = database.value(key).toObject(); // Retrieve the account details
            database.remove(key); // Temporarily remove the user object for update
            flag = true;
            break;
        }
    }

    // User found, perform the transaction
    if (flag)
    {
        double oldBalance = desiredObj.value("AccountBalance").toString().toDouble();
        double amount = data.value("Amount").toString().toDouble();
        double newBalance = oldBalance + amount; // Calculate new balance

        // Check if the new balance is non-negative
        if (newBalance < 0)
        {
            DBLogs->log("Insufficient funds.");
            jResponse["State"] = false;
            jResponse["Reason"] = -2; // Insufficient funds
            return jResponse;
        }

        // Update account balance and transaction history
        desiredObj["AccountBalance"] = QString::number(newBalance);

        // Create a new transaction record
        QJsonArray transactionHistory = desiredObj.value("TransactionHistory").toArray();
        QJsonObject transaction;
        QString date = QDateTime::currentDateTime().toString("dd-MM-yyyy");
        QString time = QDateTime::currentDateTime().toString("hh:mm:ss");
        transaction["Date"] = date;
        transaction["Time"] = time;
        transaction["Type"] = (amount > 0) ? "Deposit" : "Withdraw";
        transaction["Amount"] = QString::number(amount);
        transactionHistory.append(transaction); // Append new transaction

        desiredObj["TransactionHistory"] = transactionHistory;
        database[desiredKey] = desiredObj; // Update user object in database

        // Write the modified JSON back to the file
        if (!DataBaseFile->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            DBLogs->log("Failed to open file for reading and writing.");
            jResponse["State"] = false;
            jResponse["Reason"] = -4; // Failed to open file for reading and writing
            DataBaseFile->close();
            return jResponse;
        }

        DataBaseFile->resize(0); // Clear existing content
        QTextStream stream(DataBaseFile.get());
        stream << QJsonDocument(database).toJson(QJsonDocument::Indented);
        DataBaseFile->close();

        DBLogs->log("Transaction done successful.");
        jResponse["State"] = true; // Transaction successful
        return jResponse;
    }

    // User not found
    DBLogs->log("User: " + data.value("AccountNumber").toString() + " not found.");
    jResponse["State"] = false;
    jResponse["Reason"] = -1; // Account number not found
    return jResponse;
}

// Transfers an amount from one account to another
QJsonObject DataBaseHandler::transferAmount(const QJsonObject &data)
{
    QJsonObject jResponse;
    QJsonParseError jError;
    QJsonDocument doc;

    // Check if the database file is valid and readable
    if (!CheckDataBase(jResponse, jError, doc))
    {
        return jResponse; // Return response indicating failure
    }

    QJsonObject DataBaseObj = doc.object(); // Get the JSON object from the document
    QStringList list = DataBaseObj.keys(); // Get all keys (usernames) from the JSON object
    bool receiverFound = false;

    // Check if the receiver exists
    foreach (QString key, list)
    {
        QString number = DataBaseObj.value(key).toObject().value("AccountNumber").toString();
        if (number == data.value("ReceiverAccountNumber").toString())
        {
            receiverFound = true;
            break;
        }
    }

    // Receiver not found
    if (!receiverFound)
    {
        DBLogs->log("User: " + data.value("ReceiverAccountNumber").toString() + " receiver not found.");
        jResponse["State"] = false;
        jResponse["Reason"] = -1; // Receiver account not found
        return jResponse;
    }

    // Transfer amount: Call makeTransaction twice (once for sender and once for receiver)
    QJsonObject senderObj;
    double senderAmount = data.value("Amount").toString().toDouble() * (-1); // Amount to be subtracted from sender
    senderObj["AccountNumber"] = data.value("SenderAccountNumber").toString();
    senderObj["Amount"] = QString::number(senderAmount);

    QJsonObject senderTransResponseObj = makeTransaction(senderObj);

    // Check if the sender transaction was successful
    if (!(senderTransResponseObj.value("State").toBool()))
    {
        DBLogs->log("Sender transaction failed.");
        jResponse["State"] = false;
        jResponse["Reason"] = senderTransResponseObj.value("Reason").toString();
        return jResponse;
    }

    QJsonObject receiverObj;
    receiverObj["AccountNumber"] = data.value("ReceiverAccountNumber").toString();
    receiverObj["Amount"] = data.value("Amount").toString();

    QJsonObject receiverTransResponseObj = makeTransaction(receiverObj);

    // Check if the receiver transaction was successful
    if (!(receiverTransResponseObj.value("State").toBool()))
    {
        DBLogs->log("Receiver transaction failed.");
        jResponse["State"] = false;
        jResponse["Reason"] = receiverTransResponseObj.value("Reason").toString();
        return jResponse;
    }

    DBLogs->log("Transfer done successful.");
    jResponse["State"] = true; // Transfer successful
    return jResponse;
}
