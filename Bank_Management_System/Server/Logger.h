#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QDateTime>
#include <QDebug>

// The Logger class provides a simple logging mechanism to write messages to a file.
class Logger
{
public:
    // Constructor: Initializes the Logger with the specified log file name.
    Logger(const QString &fileName);

    // log: Writes a log message to the log file.
    // The message is prefixed with a timestamp.
    void log(const QString &message);

private:
    QFile logFile;          // QFile object to handle the log file.
    QTextStream textStream; // QTextStream object for writing text to the log file.
    QMutex mutex;           // QMutex for ensuring thread-safe access to the log file.
};

#endif // LOGGER_H
