cmake_minimum_required(VERSION 3.10)
project(logger VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Boost
find_package(Boost REQUIRED COMPONENTS log log_setup thread system filesystem)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})

# Add definitions for Boost.Log
add_definitions(-DBOOST_LOG_DYN_LINK)

# Library source files
set(LOGGER_SOURCES
    src/logger.cpp
)

# Create the logger library
add_library(logger SHARED ${LOGGER_SOURCES})

# Link Boost libraries
target_link_libraries(logger ${Boost_LIBRARIES})

# Set library output directory
set_target_properties(logger PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Install targets
install(TARGETS logger
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/
    DESTINATION include
)

# Build examples
add_subdirectory(examples)
