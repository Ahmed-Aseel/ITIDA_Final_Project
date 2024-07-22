#include <QCoreApplication> // Includes core application functionalities for non-GUI applications
#include "BankServer.h"

int main(int argc, char *argv[])
{
    // Create the QCoreApplication object, which manages application-wide resources
    QCoreApplication a(argc, argv);

    // Instantiate the BankServer object, which is responsible for handling server operations
    BankServer server;

    // Start the server by calling its StartServer method
    server.StartServer();

    // Enter the event loop. This call blocks until the application exits, processing events and handling asynchronous tasks.
    return a.exec();
}
