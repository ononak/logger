#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging {

/**
 * @brief Severity levels for logging
 */
enum class LogLevel {
    TRACE,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

/**
 * @brief Logger class using Boost.Log
 * 
 * This class provides a simple interface to the Boost.Log library
 * with support for different severity levels and console/file output.
 */
class Logger {
public:
    /**
     * @brief Initialize the logging system
     * @param logToConsole Enable console output
     * @param logToFile Enable file output
     * @param filename Log file name (if logToFile is true)
     */
    static void init(bool logToConsole = true, bool logToFile = false, 
                    const std::string& filename = "application.log");

    /**
     * @brief Log a trace message
     * @param message The message to log
     */
    static void trace(const std::string& message);

    /**
     * @brief Log a debug message
     * @param message The message to log
     */
    static void debug(const std::string& message);

    /**
     * @brief Log an info message
     * @param message The message to log
     */
    static void info(const std::string& message);

    /**
     * @brief Log a warning message
     * @param message The message to log
     */
    static void warning(const std::string& message);

    /**
     * @brief Log an error message
     * @param message The message to log
     */
    static void error(const std::string& message);

    /**
     * @brief Log a fatal message
     * @param message The message to log
     */
    static void fatal(const std::string& message);

    /**
     * @brief Log a message with specified severity level
     * @param level The severity level
     * @param message The message to log
     */
    static void log(LogLevel level, const std::string& message);

private:
    static bool initialized;
};

} // namespace logging

#endif // LOGGER_HPP
