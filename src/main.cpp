#include <iostream>
#include "map.hpp"
#define UNUSED(x) (void)(x)


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << "Hello World!\n";
    std::cout << foo() << '\n';

    return 0;
}