#include "class.hpp"
#include "class_2.hpp"

#include <iostream>

int main (int /*argc*/, char** /* argv*/)
{
    std::cout << "Use Pure virtual foo" << std::endl;

    FooConcrete foo;
    UseFoo useFoo(&foo);
    useFoo.useFoo();

    std::cout << "Use FooVirtual" << std::endl;
    Foo2Concrete foo2;
    UseFoo2 useFoo2(&foo2);
    useFoo2.useFoo();

    return 0;
}

