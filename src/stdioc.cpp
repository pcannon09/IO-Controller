#include <iostream>
#include "../include/ioController.hpp"

namespace stdioc
{
    void exception(const char *whatToExcept, const char *arg2, const char *arg3, const char *arg4, const char *arg5, const char *arg6)
    {
        ioc::color::set("red");
        std::cout<<whatToExcept<<arg2<<arg3<<arg4<<arg5<<arg6<<"\n";
        ioc::color::set("white");
        std::exit(0);
    }
}