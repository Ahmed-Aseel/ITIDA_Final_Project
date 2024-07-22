#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>    // Includes the base class for all Qt objects, providing essential features such as signals and slots
#include <QTcpSocket> // Includes the QTcpSocket class, which provides a TCP socket for network communication

// MyClient is a class that provides an interface for a TCP client.
// It manages the connection to a TCP server, sends data, and handles incoming data.
class MyClient : public QObject
{
    Q_OBJECT

public:
    // Constructor: Initializes the client with an optional parent object
    explicit MyClient(QObject *parent = nullptr);

    // Connects to a TCP server at the specified IP address and port
    void ConnectToDevice(QString ip, qint32 port);

    // Disconnects from the server
    void Disconnect();

    // Sends data to the server
    void WriteData(QByteArray data);

signals:
    // Emitted when the client successfully connects to the server
    void Connection();

    // Emitted when the client disconnects from the server
    void Disconnected();

    // Emitted when an error occurs with the socket
    void ErrorOccurred(QAbstractSocket::SocketError socketError);

    // Emitted when the socket's state changes
    void StateChanged(QAbstractSocket::SocketState socketState);

    // Emitted when new data is available to read from the server
    void ReadyRead(QByteArray data);

private slots:
    // Slot for handling the connection signal
    void onConnection();

    // Slot for handling the disconnection signal
    void onDisconnected();

    // Slot for handling errors
    void onErrorOccurred(QAbstractSocket::SocketError socketError);

    // Slot for handling state changes in the socket
    void onStateChanged(QAbstractSocket::SocketState socketState);

    // Slot for handling incoming data
    void onReadyRead();

private:
    QString ip;          // IP address of the server to connect to
    qint32 port;         // Port number of the server
    QTcpSocket socket;   // The QTcpSocket object used for communication
};

#endif // MYCLIENT_H
