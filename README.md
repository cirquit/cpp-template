## C++ Template

This template project consists of a single library, an executable that uses the library and tests for the library with the `catch` framework. `CMake` is used for the build system.

### How to use this template

```bash
> git clone https://github.com/cirquit/cpp-template
> cd cpp-template
> rm .git
> cd ..
> mv cpp-template <your-project-name>
> cd <your-project-name>
> vim CMakeLists.txt 
(modify the project/lib/executable/unique_debug_id name in the first 6 lines)
```

It should look like this,:

```cmake
set(PROJECT_NAME CppTemplate) # your project name
set(UNIQUE_DEBUG_ID CT) # this is the suffix which will be used for unique identification for our macros like DEBUG_MSG_${UNIQUE_DEBUG_ID} 
set(EXEC_NAME cpp-exec) # a name for your executable, if you have one
set(CPP_LIB_NAME cpp) # a unique library name
set(TEST_NAME cpp-test) # your executable name for tests
```

Additionally, rename the `library/example-header.h` for your needs and rename it in the corresponding `library/CMakeLists.txt`. Same goes for the `tests/example-test.cpp`

To install your library you need to change the line 9 in `library/CMakeLists.txt`:

```
     $<BUILD_INTERFACE:${CPP_TEMPLATE_SOURCE_DIR}/library> # for headers when building
```

the `CPP_TEMPLATE_SOURCE_DIR` has to be `<YOUR_PROJECT_NAME>_SOURCE_DIR` in caps and underscore for camelcase (in my case `CppTemplate`).

To enable linting and code style formatting we still need `clang-tidy` and `clang-format`. 
```bash
> sudo apt install clang-tidy-5.0 clang-format
```
In this template we're using version 5.0 of the clang extra tools. To use another version, adjust the NAMES attribute in the `CMakeLists.txt` file accordingly:
```cmake
find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy-X.X"
    DOC "Path to clang-tidy executable"
)
```
#### CMake
The property needed to integrate clang-tidy into the build process is only available from CMake Version 3.6
Check your current version with:
```bash 
> cmake --version
```
If needed, install a newer version: https://askubuntu.com/questions/829310/how-to-upgrade-cmake-in-ubuntu

#### Clang-Tidy
At the end of the `CMakeLists.txt` file we set our executable to be linted, this has to be done for each additional target to be linted. 
```cmake
if(CLANG_TIDY_EXE)
  set_target_properties(
      ${EXEC_NAME} PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()
```
The linter will be executed each time you `make` the according target.
Changes to the configuration can be done by editing `.clang-tidy` in the parent directory or by changing the `clang-tidy` flags used in the `CMakeLists.txt` file. See `clang-tidy-X.X -help` for more help.

#### Clang-Format
There's an additional target for formatting the source files called `format-my-code`.
Each time `make format-my-code` is built, the respective source files are formatted. The target files to be formatted are defined in this call:
```cmake
add_sources(src/*.cpp library/*.h tests/*.cpp)
```
Changes to the configuration can be done by editing `.clang-format` in the parent directory or by changing the `clang-format` flags used in the `CMakeLists.txt` file. See `clang-format-X.X -help` for more help.

### Build

```bash
> mkdir build && cd build
> cmake .. -DDEBUG_LEVEL=[0,1,2] -DENABLE_TESTS=[ON/OFF] -DENABLE_OPTIMIZATIONS=[ON/OFF]
> make
> ./src/[your-exe-name]
> ./test/[your-test-name]
```

### Install & link against this library 

```bash
> sudo make Install
```

Add this to the `CMakeLists.txt` file in your other project. Adapt the name and the version number (default 1.0)

```cmake
find_package(<your-library-name> 1.0 REQUIRED)
```

### Documentation

To create the documentation and open in your browser, run:

```bash
> doxygen doxygen.config
> cd Documentation/html
> firefox index.html
```
