# create exectuable 
add_executable(${EXEC_NAME} main.cpp)
# add exectuable dependencies
target_link_libraries(${EXEC_NAME} ${CPP_LIB_NAME})
