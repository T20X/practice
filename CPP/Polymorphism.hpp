#pragma once

#include <iostream>
#include <string>

namespace polymorphism
{
	class Base
	{
	public:
		Base():a(100) { std::cout << "Construct Base" << a << std::endl; }
		~Base() { std::cout << "Destructor Base" << std::endl; a=0; }
		Base(const Base& b) { a = b.a; std::cout << "Copy Base constructor" << std::endl; }

		Base& operator=(const Base& other) 
		{ 
			a=other.a; 
			std::cout << "Base assigment operator" << std::endl; 
			return *this;
		}

		Base operator+(const Base& other)
		{
			std::cout << "Operator+ Base" << std::endl;
			a += other.a;
			return *this;
		}

		int a;
	};

	class Derived : public Base
	{
	public:
		Derived():b(100) { std::cout << "Construct Derived" << a << std::endl; }
		~Derived() { std::cout << "Destructor Derived" << std::endl; }
		Derived(const Base& b) { std::cout << "Copy Derived constructor" << std::endl; }
		
		int b;
		int c;
		int d;
	};

	__declspec(noinline) Base getBaseFromDerived()
	{	
		Derived d;
		return d;
	}

	__declspec(noinline) void testReturnFromFunction()
	{
		{
			const Base& t = Base().operator+(Base());
			//const Base& b = getBaseFromDerived();
			std::cout << t.a << std::endl;

			const Base* p = new Base();
			//p->a = 20;

            const double* d = new double(12.2);
            d = new double(14);
			Base* t1 = const_cast<Base*>(p);
			//t1->a = 20;

			//std::cout << b.a << std::endl;
			//delete b;
		}
		
	}
}