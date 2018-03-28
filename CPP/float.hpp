#pragma once 

#include <math.h>
#include <cerrno>
#include <iostream>
#include <fenv.h>

namespace math
{
    void go()
    {
        errno = 0;
        int i = sqrt(-10.0);
        if (!errno)
        {
            std::cout << i;
        }
        else
        {
            std::cout << strerror(errno) << std::endl;
        }

        errno = 0;
        if (math_errhandling & MATH_ERREXCEPT) std::cout << "match exception handlign is set\n";
        if (math_errhandling & MATH_ERRNO) std::cout << "errno exception handlign is set\n";

        switch (fegetround()) {
            case FE_DOWNWARD: printf("downward"); break;
            case FE_TONEAREST: printf("to-nearest"); break;
            case FE_TOWARDZERO: printf("toward-zero"); break;
            case FE_UPWARD: printf("upward"); break;
            default: printf("unknown");
        }
    }
}



