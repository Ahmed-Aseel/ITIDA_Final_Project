#include "ClientHandler.h"

// Constructor for ClientHandler
ClientHandler::ClientHandler(qint32 cp_id, QObject *parent)
    : QThread{parent}, id{cp_id}, socket(nullptr), req_handler(nullptr)
{
    // Initializes the QThread base class with the given parent.
    // Sets the client socket descriptor (id) to the provided client ID.
    // Initializes socket and req_handler to nullptr.
    // This setup ensures that socket and req_handler are in a known state and prevents potential dangling pointer issues.
    ClientLogs = new Logger("Logs/ClientLogs.txt");
}

ClientHandler::~ClientHandler()
{
    ClientLogs->log("Destroying the ClientHandler object and closing socket");
    delete ClientLogs;
}

// Sends a response to the client
void ClientHandler::SendResponse(const QByteArray &response)
{
    // Checks if the socket is valid and open before attempting to send data
    if (socket && socket->isOpen())
    {
        socket->write(response); // Write the response data to the socket
        socket->waitForBytesWritten(); // Wait until the response is fully written to ensure it is sent
    }
}

// Handles incoming data from the client
void ClientHandler::onReadyRead()
{
    // Ensures that the socket is valid before attempting to read data
    if (socket)
    {
        QByteArray request = socket->readAll(); // Read all available data from the socket

        // Create a RequestHandler using a unique pointer for automatic memory management
        // Using std::make_unique ensures that the RequestHandler will be automatically cleaned up
        req_handler = std::make_unique<RequestHandler>();
        QByteArray response = req_handler->handleReaquest(request); // Process the request and generate a response

        SendResponse(response); // Send the generated response back to the client

        // No need to manually delete req_handler; it will be automatically cleaned up
    }
}

// Handles client disconnection
void ClientHandler::onDisconnect()
{
    // Checks if the socket is valid and open before attempting to close it
    if (socket && socket->isOpen())
    {
        socket->close(); // Close the socket connection to end communication with the client
        qDebug() << "Client " << id << " has disconnected..." << Qt::endl; // Log client disconnection
        ClientLogs->log("Client " + QString::number(id) + " has disconnected...");
    }
}

// Thread execution function
void ClientHandler::run()
{
    qDebug() << "Client " << id << " is running on thread => " << QThread::currentThreadId() << Qt::endl;
    ClientLogs->log("Client " + QString::number(id) + " is running");

    // Create a QTcpSocket instance using a unique pointer
    // Using std::make_unique ensures that the QTcpSocket will be automatically cleaned up
    socket = std::make_unique<QTcpSocket>();
    socket->setSocketDescriptor(id); // Set the socket descriptor for the client connection

    // Connect signals from QTcpSocket to the appropriate slots in this ClientHandler
    // Signals and slots are connected with Qt::DirectConnection to ensure immediate execution
    connect(socket.get(), &QTcpSocket::readyRead, this, &ClientHandler::onReadyRead, Qt::DirectConnection);
    connect(socket.get(), &QTcpSocket::disconnected, this, &ClientHandler::onDisconnect, Qt::DirectConnection);

    exec(); // Start the event loop for this thread, allowing it to process events
}
