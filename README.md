# Logger Library

A C++ logging library built on top of Boost.Log, providing a simple and efficient interface for logging messages at various severity levels.

## Features

- Multiple severity levels (TRACE, DEBUG, INFO, WARNING, ERROR, FATAL)
- Console and file output support
- Timestamped log messages
- Automatic log file rotation
- Thread-safe logging
- Easy to integrate and use

## Requirements

- C++14 or later
- CMake 3.10 or later
- Boost libraries (log, log_setup, thread, system, filesystem)

## Building

### Install Boost (if not already installed)

On Ubuntu/Debian:
```bash
sudo apt-get install libboost-all-dev
```

On macOS:
```bash
brew install boost
```

### Build the library

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

### Basic Example

```cpp
#include "logger.hpp"

int main() {
    // Initialize logger (console output only)
    logging::Logger::init(true, false);
    
    // Log messages at different severity levels
    logging::Logger::trace("This is a trace message");
    logging::Logger::debug("This is a debug message");
    logging::Logger::info("This is an info message");
    logging::Logger::warning("This is a warning message");
    logging::Logger::error("This is an error message");
    logging::Logger::fatal("This is a fatal message");
    
    return 0;
}
```

### Initialize with File Output

```cpp
// Enable both console and file logging
logging::Logger::init(true, true, "myapp.log");
```

### Using Generic Log Method

```cpp
logging::Logger::log(logging::LogLevel::INFO, "Application started");
logging::Logger::log(logging::LogLevel::ERROR, "Something went wrong");
```

## API Reference

### Initialization

```cpp
static void Logger::init(bool logToConsole = true, 
                         bool logToFile = false, 
                         const std::string& filename = "application.log");
```

Initialize the logging system. Call this once at the start of your application.

### Logging Methods

```cpp
static void trace(const std::string& message);
static void debug(const std::string& message);
static void info(const std::string& message);
static void warning(const std::string& message);
static void error(const std::string& message);
static void fatal(const std::string& message);
static void log(LogLevel level, const std::string& message);
```

## Running the Example

After building, you can run the example:

```bash
cd build
./examples/example_basic
```

## License

This project is open source and available for use.