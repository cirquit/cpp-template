# define all tests here
set(TESTS example-test.cpp)

add_executable(${TEST_NAME} catch.h main.cpp ${TESTS})

# add all used libraries
target_link_libraries(${TEST_NAME} ${CPP_LIB_NAME})
