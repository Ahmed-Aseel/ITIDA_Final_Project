#include "Logger.h"

// Constructor: Initializes the Logger with the specified log file name.
Logger::Logger(const QString &fileName)
{
    logFile.setFileName(fileName);
}

// log: Writes a log message to the log file.
// The message is prefixed with a timestamp.
void Logger::log(const QString &message)
{
    // Lock the mutex to ensure thread-safe access to the log file.
    QMutexLocker locker(&mutex);

    // Attempt to open the log file in write-only and append mode.
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        textStream.setDevice(&logFile); // Set the text stream to write to the log file.
    }
    else
    {
        qDebug() << "Failed to open log file:" << logFile.fileName();
        return; // Exit the function if the log file could not be opened.
    }

    // Format the log message with a timestamp.
    QString formattedMessage = QString("%1 | %2\n")
                                   .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz"), message);

    // Write the formatted message to the log file.
    textStream << formattedMessage;
    textStream.flush(); // Ensure the message is written to the file.
    logFile.close();    // Close the log file after writing.
}
