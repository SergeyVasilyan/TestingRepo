/**
 * @file src/logger/logger.hpp
 *
 * @brief Definition of class @ref nisseki::puente::logger::logger
 *
 *  Author Instigate Design
 *  E-mail: info@instigatedesign.com
 *  134/1 Tsarav Aghbyur St.,
 *  Yerevan, 0052, Armenia
 *  Tel:  +1-408-625-7509
 *        +49-893-8157-1771
 *        +374-60-510-710
 *
 *  Copyright (c) Nisseki Survey Inc.
 */

#pragma once

// Headers from other projects
#include "messages.hpp"

// Headers from third party libraries
#include <QFile>
#include <QObject>
#include <QTextStream>

// Headers from standard libraries
#include <string>

// Forward declarations
/// @brief logger namespace
namespace nisseki::puente::logger {
    class logger;
} // namespace nisseki::puente::logger

/**
 * @brief General purpose logging facility.
 *
 * The following functions available for use in the application:
 * Function name    Verbosity   Description
 *   message(...)     4+          print verbose messages
 *   info(...)        3           print information messages
 *   warning(...)     2           print warning messages
 *   error(...)       1           print error messages
 *
 * Verbosity is a runtime variable that determines what is printed.
 * Verbosity levels 4 or higher represent a bit mask, where each bit is
 * typically assigned to a subsystem. To print messages from that subsystem,
 * set the verbosity bit for it. If the bit is not set, message is not
 * printed.
 *
 * Verbosity levels 1, 2, and 3 are special and represent respectively errors,
 * warnings and infos. Setting verbosity to
 *    0   disables all messages
 *    1   enables errors
 *    2   enables errors and warnings
 *    3   enables errors, warnings and informations
 *
 * By default, verbosity is set to 3.
 */

class nisseki::puente::logger::logger: public QObject
{
    Q_OBJECT
signals:
    /// @brief The signal is emitted every time when new message is logged
    void entry_logged();

    /// @name Static interface
public:
    /// @brief Returns reference to the logger object
    static logger& get() noexcept;

    /**
     * @brief Set up logger logfile and verbosity
     * @param path - path where log file must be created
     */
    void setup_logfile(const QString& path) noexcept;

    /**
     * @brief Close log file
     */
    void close_logfile() noexcept;

    /**
     * @brief The function prints the error message type, time, message, which
     * consist of message-id and the message text, and end-of-line.
     * For example:
     *
     * @code
     * namespace MSGS {
     * const message IF {"XML_PARSER-001", "Invalid XML file: %s"};
     * }
     * @endcode
     * @code
     * logger::error(MSGS::IXF, xml.name().c_str());
     * @endcode
     * The result message in logfile looks like the below:
     * @code
     * ERROR  [10:11:27] [XML_PARSER-001]: Invalid XML file: design.xml
     * @endcode
     */
    static void error(const MSGS::message m, ...) noexcept;
     
    /**
     * @brief Method to print out warning message.
     */
    static void warning(const MSGS::message m, ...) noexcept;
    
    /**
     *  @brief Method to print out info message.
     */
    static void info(const MSGS::message m, ...) noexcept;

    /**
     * @brief Print out information message if the current verbosity
     * matches message level.
     *
     * @param level - level of the message
     * @param m - message
     */
    static void message(MSGS::verbosity level, const MSGS::message m, ...)
        noexcept;

    /**
     * @brief Generates the log file name
     *
     * @param start - prefix
     * @param del - delimeter
     * @param ext - file extension
     */
    static QString generate_logfile_name(
        const QString& start = "out",
        const QString& del = "_",
        const QString& ext = "log") noexcept;

    /// @name Logger verbosity and log file
public:
    /// @brief Returns current verbosity level.
    unsigned int get_verbosity() const noexcept;

    /// @brief Sets verbosity level.
    void set_verbosity(unsigned int level) noexcept;

    /// @brief Returns opened log file name if any
    QString get_logfile_name() const noexcept;

    /**
     * @brief Returns last message from logger
     * @return - last message string object
     */
    static const std::string& get_last_message() noexcept;

private:
    /**
     * Print all messages to a file (by default it is standard output)
     * @param name - logfile name
     */
    void open_logfile(const QString& name) noexcept;

private:
    void print(unsigned int  level, const MSGS::message& m, va_list args);

    static constexpr const char* m_message[4] = {"MESSAGE",
        "ERROR  ", "WARNING", "INFO   "};

    unsigned int m_verbosity;
    QFile m_logfile;
    std::string m_last_message;

private:
    /// @brief The only available constructor
    logger() noexcept;

    /// @brief Destructor
    ~logger() noexcept = default;

public:
    /// @name Deleted special member functions
    /// This class is not copy-constructible
    logger(const logger&) = delete;

    /// This class is not move-constructible
    logger(logger&&) = delete;

    /// This class is not copy-assignable
    logger& operator=(const logger&) = delete;

    /// This class is not move-assignable
    logger& operator=(logger&&) = delete;
};

// vim:fo=croqt:cindent:expandtab:textwidth=80:tabstop=4:shiftwidth=4
