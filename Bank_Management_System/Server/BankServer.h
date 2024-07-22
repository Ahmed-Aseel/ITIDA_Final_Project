#ifndef BANKSERVER_H
#define BANKSERVER_H

#include <QObject>      // Includes the base class for all Qt objects
#include <QTcpServer>   // Includes the class for TCP server functionalities
#include <QTextStream>  // Includes the class for text stream handling
#include <QDebug>       // Includes the class for debugging and logging
#include "Logger.h"

// The BankServer class is responsible for managing incoming client connections.
// It inherits from QTcpServer to handle TCP connections and provide server functionality.
class BankServer : public QTcpServer
{
    Q_OBJECT // Macro to enable Qt's meta-object system, including signals and slots

public:
    // Constructor for BankServer. Initializes the server with an optional parent QObject.
    explicit BankServer(QObject *parent = nullptr);
    ~BankServer();

    // Method to start the server and begin listening for incoming connections.
    void StartServer();

    // Method to stop the server and close the listening socket.
    void QuitServer();

signals:
         // Define signals here if needed for communication with other objects.
         // Signals are emitted to indicate events or data changes.

protected:
    // Override the QTcpServer::incomingConnection() method to handle new client connections.
    // This method is called when a new client connects to the server.
    void incomingConnection(qintptr handle) override;

private:
    QTextStream qin; // QTextStream for reading input from the standard input (stdin)
    QTextStream qout; // QTextStream for writing output to the standard output (stdout)
    qint32 port; // Port number on which the server listens for incoming connections
    Logger *ServerLogs;
};


#endif // BANKSERVER_H
