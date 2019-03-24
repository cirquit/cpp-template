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

#ifndef EXAMPLE_HEADER_H
#define EXAMPLE_HEADER_H

#include "autogen-CT-macros.h"

/*!
 *  \addtogroup example
 *  @{
 */

/** \brief EXAMPLE namespace
 *
 */
namespace example {

/** \brief This is an exemplary function for macro testing reasons
 * This is the additional comments section.
 */
int foo() {
  DEBUG_MSG_CT("Debug was called from here - " << 23 << '\n');
  DEBUG_CRIT_MSG_CT("Critical Debug was called from here - " << '\n'
                                                             << "   - some list " << '\n'
                                                             << "   - some list " << '\n'
                                                             << "   - some list " << '\n'
                                                             << "   - some list " << '\n');
  return 1;
}

}  // namespace example

#endif  // EXAMPLE_HEADER_H
