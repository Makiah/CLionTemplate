cmake_minimum_required(VERSION 3.14)
project(CLionTemplate)

# From `brew install qt`
set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.13.1")

# I think this isjust general stuff
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files

# for googletest
add_subdirectory(googletest)

# For qt
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

# For googletest
find_package(Threads REQUIRED)
enable_testing()
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

# easier than typing everything out (ain't nobody got time for that)
file(GLOB SOURCES "src/*.h" "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(runAllTests tests.cpp ${TEST_SOURCES} ${SOURCES})
add_executable(myProject main.cpp ${SOURCES})

# Link Qt libraries
target_link_libraries(myProject Qt5::Core Qt5::Widgets Qt5::Gui)

# Add testing
target_link_libraries(runAllTests gtest gtest_main)
add_test(AllTests runAllTests)