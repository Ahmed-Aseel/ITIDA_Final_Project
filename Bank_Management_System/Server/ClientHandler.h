#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>    // Includes the base class for all Qt objects, providing essential features such as signals and slots
#include <QThread>    // Includes the QThread class, which enables multi-threading capabilities by allowing execution of code in separate threads
#include <QTcpSocket> // Includes the QTcpSocket class, which provides a TCP socket for network communication
#include <QDebug>     // Includes the QDebug class, used for outputting debug information and logging
#include <memory>     // Includes smart pointers such as std::unique_ptr
#include "RequestHandler.h" // Includes the header file for handling client requests
#include "Logger.h"

// The ClientHandler class is designed to manage communication with a single client in a separate thread.
// It inherits from QThread to enable concurrent processing.
class ClientHandler : public QThread
{
    Q_OBJECT // Macro to enable the Qt meta-object system for signals and slots

public:
    // Constructor to initialize the ClientHandler with a client socket descriptor and an optional parent QObject.
    // The client socket descriptor (cp_id) identifies the client's connection.
    explicit ClientHandler(qint32 cp_id, QObject *parent = nullptr);
    ~ClientHandler();

    // Method to send a response to the client.
    // The response is provided as a QByteArray.
    void SendResponse(const QByteArray &response);

signals:
         // Define signals here if needed for communication with other objects.
         // Signals are emitted to indicate events or data changes.

public slots:
    // Slot to handle incoming data from the client.
    // This slot is triggered when there is new data available to read.
    void onReadyRead();

    // Slot to handle client disconnection.
    // This slot is triggered when the client disconnects from the server.
    void onDisconnect();

protected:
    // Overrides the QThread::run() method to define the thread's execution behavior.
    // This method is called when the thread starts and should contain the main processing loop for the client.
    void run() override;

private:
    qint32 id; // Client socket descriptor to identify the client's connection.
    std::unique_ptr<QTcpSocket> socket; // Unique pointer to the QTcpSocket used to communicate with the client.
    std::unique_ptr<RequestHandler> req_handler; // Unique pointer to the RequestHandler that processes client requests.
    Logger *ClientLogs;
};

#endif // CLIENTHANDLER_H
