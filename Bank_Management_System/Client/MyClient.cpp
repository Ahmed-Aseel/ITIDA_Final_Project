#include "MyClient.h"

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    // Connect signals from QTcpSocket to slots in MyClient
    connect(&socket, &QTcpSocket::connected, this, &MyClient::onConnection);
    connect(&socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
    connect(&socket, &QTcpSocket::errorOccurred, this, &MyClient::onErrorOccurred);
    connect(&socket, &QTcpSocket::stateChanged, this, &MyClient::onStateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
}

void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    // If the socket is already open, check if the connection parameters match
    if (socket.isOpen())
    {
        if ((this->ip == ip) && (this->port == port))
        {
            return; // Already connected to the correct device
        }
        else
        {
            socket.close(); // Close the existing connection if parameters differ
        }
    }

    // Update the IP and port and attempt to connect
    this->port = port;
    this->ip = ip;
    socket.connectToHost(this->ip, this->port);
}

void MyClient::Disconnect()
{
    // Close the socket if it's open
    if (socket.isOpen())
    {
        socket.close();
    }
}

void MyClient::WriteData(QByteArray data)
{
    // Write data to the socket if it's open
    if (socket.isOpen())
    {
        socket.write(data);
    }
}

void MyClient::onConnection()
{
    // Emit the Connection signal when the socket is connected
    emit Connection();
}

void MyClient::onDisconnected()
{
    // Emit the Disconnected signal when the socket is disconnected
    emit Disconnected();
}

void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    // Emit the ErrorOccurred signal with the socket error code
    emit ErrorOccurred(socketError);
}

void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    // Close the socket if it transitions to UnconnectedState
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    // Emit the StateChanged signal with the new socket state
    emit StateChanged(socketState);
}

void MyClient::onReadyRead()
{
    // Read all available data from the socket and emit the ReadyRead signal
    QByteArray data = socket.readAll();
    emit ReadyRead(data);
}
