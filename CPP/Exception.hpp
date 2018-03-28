#pragma once

#include <exception>
#include <stdexcept>
#include <iostream>

namespace except
{ 
    class A
    {
    public:
        ~A()
        {
            //throw std::runtime_error("hello!");
        }
        void foo() /*noexcept*/
        {
            throw std::runtime_error("hello!");
        }
    };
     

    void go()
    {
        try
        {
            A v1;
            v1.foo();
        }
        catch (...)
        {
        }
        
    }
}