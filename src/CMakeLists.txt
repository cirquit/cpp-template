# all library sources
set(SOURCES map.hpp)

# create library
add_library(${LIB_NAME} ${SOURCES})
target_link_libraries(${LIB_NAME}) #{OTHER SOURCES}
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# create exectuable 
add_executable(${EXEC_NAME} main.cpp)
# add exectuable dependencies
target_link_libraries(${EXEC_NAME} ${LIB_NAME})
