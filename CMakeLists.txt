set(PROJECT_NAME CppTemplate)
set(EXEC_NAME cpp-exec)
set(LIB_NAME cpp)
set(TEST_NAME cpp-test)

project (${PROJECT_NAME})
cmake_minimum_required (VERSION 3.5.1)

# set compiler flags
set (CMAKE_CXX_COMPILER=gcc)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g") #-pthread -Wall -Wextra -Werror -Wfatal-errors -pedantic -g")

# add the code
add_subdirectory(src)
add_subdirectory(test)
