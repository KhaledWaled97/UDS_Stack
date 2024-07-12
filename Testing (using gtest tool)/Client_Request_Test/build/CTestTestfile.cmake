# CMake generated Testfile for 
# Source directory: E:/NTI/Brightskies_Internship/Task 4/Client_Request_Test
# Build directory: E:/NTI/Brightskies_Internship/Task 4/Client_Request_Test/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Client_Test_App]=] "E:/NTI/Brightskies_Internship/Task 4/Client_Request_Test/build/Client_Test_App.exe")
set_tests_properties([=[Client_Test_App]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/NTI/Brightskies_Internship/Task 4/Client_Request_Test/CMakeLists.txt;25;add_test;E:/NTI/Brightskies_Internship/Task 4/Client_Request_Test/CMakeLists.txt;0;")
subdirs("googletest")
