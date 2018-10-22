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
> doxygen config.doxygen
> cd Documentation/html
> firefox index.html
```