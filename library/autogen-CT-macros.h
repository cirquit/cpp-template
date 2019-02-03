
#ifndef AUTOGEN_CT_MACROS_H
#define AUTOGEN_CT_MACROS_H
#include <string.h>
//! macro preprocessing of the file standart to get the filename instead of the full filepath
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#include <iostream>
//! logging based on the DEBUG_LEVEL_CT defined while building with cmake (only active with DEBUG_LEVEL=2)
#define DEBUG_MSG_CT(msg) std::cerr << "[CT - " << __FILENAME__ << ':' << __LINE__ << ':' << __func__ << "()]: " << msg;
//! logging based on the DEBUG_LEVEL_CT defined while building with cmake (active with DEBUG_LEVEL=1 and 2)
#define DEBUG_CRIT_MSG_CT(msg) DEBUG_MSG_CT(msg)
#endif  // AUTOGEN_CT_MACROS_H