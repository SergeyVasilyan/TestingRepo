/**
 * @file src/logger/logger.cpp
 *
 * @brief Implementation of class @ref nisseki::puente::logger::logger
 *
 * Author Instigate Design
 * E-mail: info@instigatedesign.com
 * 134/1 Tsarav Aghbyur St.,
 * Yerevan, 0052, Armenia
 * Tel:  +1-408-625-7509
 *       +49-893-8157-1771
 *       +374-60-510-710
 *
 * Copyright (c) Nisseki Survey Inc.
 */

  // Headers from this project
#include "logger.hpp"

// Headers from other projects

// Headers from third party libraries
#include <QDir>
#include <QFileInfo>
#include <QTime>

// Headers from standard libraries
#include <cassert>
#include <cstdio>

nisseki::puente::logger::logger&
nisseki::puente::logger::logger::
get() noexcept
{
    static logger l;
	return l;
}

void nisseki::puente::logger::logger::
setup_logfile(const QString& path) noexcept
{
    assert(QFileInfo(path).exists());
    if (m_logfile.isOpen()) {
        m_logfile.close();
    }
    assert(! m_logfile.isOpen());
    open_logfile(path + "/" + logger::generate_logfile_name());
}

void nisseki::puente::logger::logger::
close_logfile() noexcept
{
    if (m_logfile.isOpen()) {
        m_logfile.close();
    }
}

void nisseki::puente::logger::logger::
error(const MSGS::message m, ...) noexcept
{
    if (MSGS::ERROR <= get().m_verbosity) {
        va_list args;
	    va_start(args, m);
	    get().print(static_cast<int>(MSGS::ERROR), m, args);
        va_end(args);
    }
}

void nisseki::puente::logger::logger::
warning(const MSGS::message m, ...) noexcept
{
    if (MSGS::WARNING <= get().m_verbosity) {
        va_list args;
	    va_start(args, m);
	    get().print(static_cast<int>(MSGS::WARNING), m, args);
        va_end(args);
    }
}

void nisseki::puente::logger::logger::
info(const MSGS::message m, ...) noexcept
{
     if (MSGS::INFO <= get().m_verbosity) {
        va_list args;
	    va_start(args, m);
	    get().print(static_cast<int>(MSGS::INFO), m, args);
        va_end(args);
    }
}

void nisseki::puente::logger::logger::
message(MSGS::verbosity level, const MSGS::message m, ...) noexcept
{
    if (get().m_verbosity & level) {
        va_list args;
	    va_start(args, m);
	    get().print(0, m, args);
        va_end(args);
    }
}

void nisseki::puente::logger::logger::
print(unsigned int level, const MSGS::message& m, va_list args)
{
    constexpr int BUFFER_SIZE = 4096;
    static char _buffer[BUFFER_SIZE + 1] = {};
    const QString t = QTime::currentTime().toString();
    // TYPE [time] [COMPONENT-ID]: text
    int count = snprintf(_buffer, BUFFER_SIZE, "%s [%s] [%s]: ",
                         m_message[level & 3], t.toStdString().c_str(),
                         m.name.data());
    int msg_pos = count;
    count += vsnprintf(_buffer + count, BUFFER_SIZE - count,
                       m.description.data(), args);
    m_last_message = _buffer + msg_pos;
    if (count >= BUFFER_SIZE) {
        count = BUFFER_SIZE - 2;
    }
    _buffer[count++] = '\n';
    _buffer[count++] = '\0';
    assert(m_logfile.isOpen());
    m_logfile.write(_buffer);
    m_logfile.flush();
    assert(m_logfile.isOpen());
    emit entry_logged();
}

QString nisseki::puente::logger::logger::
generate_logfile_name(const QString& start,
                      const QString& del,
                      const QString& ext) noexcept
{
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();
    const QString name = start +
        del + d.toString("dd") +
        del + d.toString("MM") +
        del + t.toString("HH") +
        del + t.toString("mm") + "." + ext;
    return name;
}

void nisseki::puente::logger::logger::
set_verbosity(unsigned int level) noexcept
{
    m_verbosity = level;
}

unsigned int nisseki::puente::logger::logger::
get_verbosity() const noexcept
{
    return m_verbosity;
}

void nisseki::puente::logger::logger::
open_logfile(const QString& name) noexcept
{
    assert(! name.isEmpty());
    if (m_logfile.isOpen()) {
        m_logfile.close();
    }
    const QDir log_file_path{ QFileInfo(name).absolutePath() };
    if (! log_file_path.exists()) {
        QDir().mkdir(log_file_path.absolutePath());
        assert(log_file_path.exists());
    }
    m_logfile.setFileName(name);
    m_logfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    assert(m_logfile.error() == QFile::NoError);
    assert(m_logfile.isOpen());
}

QString nisseki::puente::logger::logger::
get_logfile_name() const noexcept
{
    return m_logfile.fileName();
}

const std::string& nisseki::puente::logger::logger::
get_last_message() noexcept
{
    return get().m_last_message;
}

nisseki::puente::logger::logger::
logger() noexcept
    : m_verbosity{ 3 }
    , m_logfile{ this }
{
    m_logfile.open(stdout, QIODevice::WriteOnly | QIODevice::Text);
    assert(m_logfile.error() == QFile::NoError);
    assert(m_logfile.isOpen());
}

// vim:fo=croqt:cindent:expandtab:textwidth=80:tabstop=4:shiftwidth=4
