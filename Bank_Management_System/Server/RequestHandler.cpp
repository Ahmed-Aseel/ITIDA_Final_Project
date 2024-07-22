#include "RequestHandler.h"

// Initialize the static mutex for synchronizing access across instances
QMutex RequestHandler::globalMutex;

// Constructor for RequestHandler
RequestHandler::RequestHandler()
{
    // Initialize the database handler instance using a shared pointer
    db_handler = std::shared_ptr<DataBaseHandler>(DataBaseHandler::getInstance());
    RequestLogs = new Logger("Logs/RequestLogs.txt");
}

RequestHandler::~RequestHandler()
{
    RequestLogs->log("Destroying the RequestHandler object along with its resources");
    delete RequestLogs;
}

// Validates the hash in the JSON request to ensure data integrity
bool RequestHandler::validateHashRequest(QJsonObject &requestObject)
{
    // Extract the hash from the JSON request
    QString receivedHashHex = requestObject.value("Hash").toString();
    QByteArray receivedHash = QByteArray::fromHex(receivedHashHex.toUtf8());

    // Remove the hash field from the request object before computing its hash
    requestObject.remove("Hash");
    QJsonDocument requestWithoutHash(requestObject);

    // Compute the hash of the request object (excluding the hash field)
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(requestWithoutHash.toJson());
    QByteArray computedHash = hash.result();

    // Compare the computed hash with the received hash
    if (computedHash == receivedHash)
    {
        // Hash validation succeeded
        // qDebug() << "Request is verified and integrity is intact.";
        return true;
    }
    else
    {
        // Hash validation failed
        // qDebug() << "Request verification failed. Integrity is compromised.";
        return false;
    }
}

// Adds a hash to the response object to ensure its integrity
void RequestHandler::hashResponse(QJsonObject &responseObject)
{
    // Convert the JSON object to a JSON document
    QJsonDocument responseDoc(responseObject);

    // Compute the hash of the response JSON document
    QCryptographicHash hashedResponse(QCryptographicHash::Sha256);
    hashedResponse.addData(responseDoc.toJson());

    // Include the computed hash in the JSON response object
    responseObject["Hash"] = QString((hashedResponse.result()).toHex());
}

// Handles the incoming request and generates a response
QByteArray RequestHandler::handleReaquest(const QByteArray &request)
{
    // Parse the incoming JSON request
    QJsonDocument doc = QJsonDocument::fromJson(request);
    QJsonObject requestObj = doc.object();
    QJsonObject db_response; // Object to hold the database response
    QJsonDocument docResponse; // JSON document for the response
    QByteArray response; // Byte array to hold the final response
    qint32 processID = requestObj.value("RequestID").toInt(); // Extract the request ID

    // Validate the request's hash before processing
    if (validateHashRequest(requestObj))
    {
        // Lock the global mutex to ensure thread-safe access to the database
        QMutexLocker locker(&globalMutex);

        // Process the request based on its ID
        switch(processID)
        {
        case LogIn_ID:
            RequestLogs->log("Handle logIn request");
            db_handler->DBLogs->log("Handle logIn request");
            db_response = db_handler->logIn(requestObj);
            break;

        case CreateUser_ID:
            RequestLogs->log("Handle createUser request");
            db_handler->DBLogs->log("Handle createUser request");
            db_response = db_handler->createUser(requestObj);
            break;

        case UpDateUser_ID:
            RequestLogs->log("Handle updateUser request");
            db_handler->DBLogs->log("Handle updateUser request");
            db_response = db_handler->updateUser(requestObj);
            break;

        case DeleteUser_ID:
            RequestLogs->log("Handle deleteUser request");
            db_handler->DBLogs->log("Handle deleteUser request");
            db_response = db_handler->deleteUser(requestObj);
            break;

        case ViewBankDB_ID:
            RequestLogs->log("Handle viewBankDB request");
            db_handler->DBLogs->log("Handle viewBankDB request");
            db_response = db_handler->viewBankDB();
            break;

        case GetAccount_ID:
            RequestLogs->log("Handle getAccount_Number request");
            db_handler->DBLogs->log("Handle getAccount_Number request");
            db_response = db_handler->getAccount_Number(requestObj);
            break;

        case GetBalance_ID:
            RequestLogs->log("Handle viewAccount_Balance request");
            db_handler->DBLogs->log("Handle viewAccount_Balance request");
            db_response = db_handler->viewAccount_Balance(requestObj);
            break;

        case ViewTransactionHistory_ID:
            RequestLogs->log("Handle viewTransaction_History request");
            db_handler->DBLogs->log("Handle viewTransaction_History request");
            db_response = db_handler->viewTransaction_History(requestObj);
            break;

        case MakeTransaction_ID:
            RequestLogs->log("Handle makeTransaction request");
            db_handler->DBLogs->log("Handle makeTransaction request");
            db_response = db_handler->makeTransaction(requestObj);
            break;

        case TransferAmount_ID:
            RequestLogs->log("Handle transferAmount request");
            db_handler->DBLogs->log("Handle transferAmount request");
            db_response = db_handler->transferAmount(requestObj);
            break;

        default:
            // Handle unknown request ID
            RequestLogs->log("Unknown request");
            db_response["State"] = false;
            db_response["Reason"] = -7;
            break;
        }
    }
    else
    {
        // Handle invalid request hash
        RequestLogs->log("Invalid request hash");
        db_response["State"] = false;
        db_response["Reason"] = -6;
    }

    // Add the response ID and hash to the response object
    db_response["ResponseID"] = processID;
    hashResponse(db_response);

    // Convert the response object to a JSON document and then to a QByteArray
    docResponse.setObject(db_response);
    response = docResponse.toJson();

    return response;
}
