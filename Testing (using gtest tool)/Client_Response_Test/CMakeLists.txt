cmake_minimum_required(VERSION 3.27)

# Project name
project(Client_Response_Test C CXX)

# Specify the C++ standard
set(CMAKE_C_STANDARD 99)

# Add the C source file
add_library(APP_UDS_Diag APP_UDS_Diag.c)

# Add Google Test
add_subdirectory(googletest)

# Add the test executable
add_executable(Client_Test_App Client_Test_App.cpp)

# Link the test executable with Google Test and your C library
target_link_libraries(Client_Test_App gtest gtest_main APP_UDS_Diag)

# Enable testing
enable_testing()

# Add the test
add_test(NAME Client_Test_App COMMAND Client_Test_App)
