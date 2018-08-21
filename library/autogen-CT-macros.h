// Copyright 2019 municHMotorsport e.V. <info@munichmotorsport.de>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AUTOGEN_CT_MACROS_H
#define AUTOGEN_CT_MACROS_H

// if any debug level is defined, we create the appropriate macros for logging based on the -DDEBUG_LEVEL=X specified while building with cmake
#if  defined(DEBUG_LEVEL_CT_0) \
  || defined(DEBUG_LEVEL_CT_1) \
  || defined(DEBUG_LEVEL_CT_2) \

    #include <string.h>
    //! macro preprocessing of the file standart to get the filename instead of the full filepath
    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

    // if debugging is disabled, the macros don't do anything 
    #if DEBUG_LEVEL_CT_0

    //! logging based on the DEBUG_LEVEL defined while building with cmake (only active with DEBUG_LEVEL=2)
    #define DEBUG_MSG_CT(msg)
    //! logging based on the DEBUG_LEVEL defined while building with cmake (active with DEBUG_LEVEL=1 and 2)
    #define DEBUG_CRIT_MSG_CT(msg)

    // if critical debugging is enabled, only the DEBUG_CRIT_MSG_CT prints the message to std::cerr
    #elif DEBUG_LEVEL_CT_1

    #include <iostream>
    //! logging based on the DEBUG_LEVEL defined while building with cmake (only active with DEBUG_LEVEL=2)
    #define DEBUG_MSG_CT(msg)
    //! logging based on the DEBUG_LEVEL defined while building with cmake (active with DEBUG_LEVEL=1 and 2)
    #define DEBUG_CRIT_MSG_CT(msg) std::cerr << "[CT INFO - " \
                        << __FILENAME__ << ':' \
                        << __LINE__ << ':'     \
                        << __func__ << "()]: "    \
                        << msg;

    // if debugging is enabled, both macros print the messages to std::cerr
    #else

    #include <iostream>
    //! logging based on the DEBUG_LEVEL defined while building with cmake (only active with DEBUG_LEVEL=2)
    #define DEBUG_MSG_CT(msg) std::cerr << "[CT INFO - " \
                        << __FILENAME__ << ':' \
                        << __LINE__ << ':'     \
                        << __func__ << "()]: "    \
                        << msg;
    //! logging based on the DEBUG_LEVEL defined while building with cmake (active with DEBUG_LEVEL=1 and 2)
    #define DEBUG_CRIT_MSG_CT(msg) DEBUG_MSG_CT(msg)
    #endif
#endif 
#endif // AUTOGEN_CT_MACROS_H