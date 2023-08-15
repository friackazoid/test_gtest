#include "class.hpp"

#include <iostream>

int main (int /*argc*/, char** /* argv*/)
{
    FooConcrete foo;
    UseFoo useFoo(&foo);
    std::cout << "Hello World!" << std::endl;

    return 0;
}

