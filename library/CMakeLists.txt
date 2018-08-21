# all library sources
set(SOURCES example-header.h autogen-${UNIQUE_DEBUG_ID}-macros.h)

# create library
add_library(${CPP_LIB_NAME} ${SOURCES})

# used for 'make install'
target_include_directories(${CPP_LIB_NAME} PUBLIC
     $<BUILD_INTERFACE:${CPP_TEMPLATE_SOURCE_DIR}/library> # for headers when building
     $<INSTALL_INTERFACE:${include_dest}>                  # for client in install mode
)

# linking library
target_link_libraries(${CPP_LIB_NAME}) #{OTHER SOURCES}
set_target_properties(${CPP_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# used for 'make install', too
install(FILES ${SOURCES} DESTINATION "${include_dest}")
install(TARGETS ${CPP_LIB_NAME} EXPORT ${CPP_LIB_NAME} DESTINATION "${main_lib_dest}")

