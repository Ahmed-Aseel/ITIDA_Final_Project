#include <QDir>
#include <memory>          // Includes smart pointers such as std::unique_ptr
#include "BankServer.h"
#include "ClientHandler.h" // Includes the custom header for handling client connections

// Constructor for BankServer
BankServer::BankServer(QObject *parent)
    : QTcpServer{parent}, qin{stdin}, qout{stdout}, port{0}
{
    // Initializes the QTcpServer base class with the given parent
    // Initializes QTextStream objects qin and qout to read from stdin and write to stdout
     // Initialize port to 0
    QDir dir;
    QString folderPath = "Logs";

    // Check if the directory exists
    if (!dir.exists(folderPath))
    {
        // Attempt to create the directory
        dir.mkpath(folderPath);
    }

    ServerLogs = new Logger("Logs/ServerLogs.txt");
}

BankServer::~BankServer()
{
    ServerLogs->log("Destroying the BankServer object along with its resources");
    delete ServerLogs;
}

// Starts the server and begins listening on the specified port
void BankServer::StartServer()
{
    qout << "Enter port number to listen on: ";
    qout.flush();  // Ensures the prompt is immediately visible to the user

    // Read the port number from the standard input and convert it to an integer
    port = qin.readLine().toInt();

    // Start listening on the specified port, accepting connections from any IP address
    this->listen(QHostAddress::Any, port);

    // Check if the server successfully started listening
    if (this->isListening())
    {
        ServerLogs->log("Server is up and listening on port " + QString::number(port));
        qDebug() << "Server is up and listening on port " << port << Qt::endl;
    }
    else
    {
        ServerLogs->log("Server cannot listen on port " + QString::number(port));
        qDebug() << "Server cannot listen on port " << port << Qt::endl;
    }
}

// Stops the server and closes the listening socket
void BankServer::QuitServer()
{
    ServerLogs->log("Closing server...");
    qDebug() << "Closing server...";
    this->close();  // Closes the server, stopping it from accepting new connections
}

// Handles incoming client connections
void BankServer::incomingConnection(qintptr handle)
{
    ServerLogs->log("Client " + QString::number(handle) + " connecting....");
    qDebug() << "Client " << handle << " connecting....";

    // Create a unique_ptr for the ClientHandler to manage its lifecycle
    auto clientHandler = std::make_unique<ClientHandler>(handle, this);

    // Connect the finished signal from ClientHandler to its own deleteLater slot
    // This ensures the ClientHandler object is properly deleted when its work is done
    connect(clientHandler.get(), &QThread::finished, clientHandler.get(), &QThread::deleteLater);

    // Start the client handler in a new thread
    clientHandler->start();

    // Release the unique_ptr ownership to the thread to ensure proper cleanup
    // This is needed because QThread takes ownership of the ClientHandler
    clientHandler.release();
}
