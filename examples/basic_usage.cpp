#include "logger.hpp"
#include <iostream>

int main() {
    // Initialize logger with console output only
    logging::Logger::init(true, false);

    std::cout << "=== Basic Logger Example ===" << std::endl;
    std::cout << std::endl;

    // Log messages at different severity levels
    logging::Logger::trace("This is a trace message");
    logging::Logger::debug("This is a debug message");
    logging::Logger::info("This is an info message");
    logging::Logger::warning("This is a warning message");
    logging::Logger::error("This is an error message");
    logging::Logger::fatal("This is a fatal message");

    std::cout << std::endl;
    std::cout << "=== Using log() method with LogLevel ===" << std::endl;
    std::cout << std::endl;

    // Alternative: use the generic log method
    logging::Logger::log(logging::LogLevel::INFO, "Application started successfully");
    logging::Logger::log(logging::LogLevel::WARNING, "Memory usage is high");
    logging::Logger::log(logging::LogLevel::ERROR, "Failed to open configuration file");

    std::cout << std::endl;
    std::cout << "=== Example completed ===" << std::endl;

    return 0;
}
