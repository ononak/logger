#include "logger.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging {

bool Logger::initialized = false;

void Logger::init(bool logToConsole, bool logToFile, const std::string& filename) {
    if (initialized) {
        return;
    }

    namespace logging = boost::log;
    namespace src = boost::log::sources;
    namespace sinks = boost::log::sinks;
    namespace keywords = boost::log::keywords;
    namespace expr = boost::log::expressions;

    // Add common attributes
    logging::add_common_attributes();

    // Console sink
    if (logToConsole) {
        logging::add_console_log(
            std::cout,
            keywords::format = (
                expr::stream
                    << "[" << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                    << "] [" << logging::trivial::severity
                    << "] " << expr::smessage
            )
        );
    }

    // File sink
    if (logToFile) {
        logging::add_file_log(
            keywords::file_name = filename,
            keywords::rotation_size = 10 * 1024 * 1024, // 10 MB
            keywords::format = (
                expr::stream
                    << "[" << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                    << "] [" << logging::trivial::severity
                    << "] " << expr::smessage
            ),
            keywords::auto_flush = true
        );
    }

    initialized = true;
}

void Logger::trace(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(trace) << message;
}

void Logger::debug(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(debug) << message;
}

void Logger::info(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(info) << message;
}

void Logger::warning(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(warning) << message;
}

void Logger::error(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(error) << message;
}

void Logger::fatal(const std::string& message) {
    if (!initialized) {
        init();
    }
    BOOST_LOG_TRIVIAL(fatal) << message;
}

void Logger::log(LogLevel level, const std::string& message) {
    switch (level) {
        case LogLevel::TRACE:
            trace(message);
            break;
        case LogLevel::DEBUG:
            debug(message);
            break;
        case LogLevel::INFO:
            info(message);
            break;
        case LogLevel::WARNING:
            warning(message);
            break;
        case LogLevel::ERROR:
            error(message);
            break;
        case LogLevel::FATAL:
            fatal(message);
            break;
    }
}

} // namespace logging
