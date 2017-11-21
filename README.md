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
(modify the project/lib/executable names)
```

### Build

```bash
> mkdir build && cd build
> cmake .. -DDEBUG_MODE=1
> make
> ./src/[your-exe-name]
> ./test/[your-test-name]
```
