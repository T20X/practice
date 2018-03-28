/*When I want to expose some but not all of a base class's interface.
Public inheritance would be a lie, as Liskov substitutability is broken, 
whereas composition would mean writing a bunch of forwarding functions.
When I want to derive from a concrete class without a virtual destructor. 
Public inheritance would invite clients to delete through a pointer-to-base, invoking undefined behaviour.

When implementing the Adapter Pattern, inheriting privately from the Adapted class saves having to forward to an enclosed instance.

A legitimate, long-term use for private inheritance is when you want to build a class Fred that uses code in a class Wilma, 
and the code from class Wilma needs to invoke member functions from your new class, Fred. 
In this case, Fred calls non-virtuals in Wilma, and Wilma calls (usually pure virtuals) in itself,
which are overridden by Fred. This would be much harder to do with composition.


If you have reasons to inherit something privately and want to make those benefits 
(i.e. that would-be member of your class or the typedefs) accessible to derived classes,
use protected inheritance. Obviously, private inheritance should be used scarcely, 
and protected inheritance even more so

The canonical usage of private inheritance is the "implemented in terms of" relationship (thanks to Scott Meyers' 'Effective C++' for this wording). 
In other words, the external interface of the inheriting class has no (visible) relationship to the inherited class, 
but it uses it internally to implement its functionality.*/

#include <vector>
#include <iostream>

class MyVector : private std::vector<int>
{
public:
    // Using declarations expose the few functions my clients need 
    // without a load of forwarding functions. 
    using std::vector<int>::push_back;
    // etc...  
};

class Notifier
{
public:
	virtual void onChange() = 0;
};

class A : public virtual Notifier
{
protected:
	//using Notifier::onChange;
	void start() { std::cout << "A::start()" << std::endl; onChange(6); }	
	virtual void onChange(int i) = 0;
	void customA(){}
};

class B : public virtual Notifier
{
protected:
	void start() { std::cout << "B::start()" << std::endl; onChange(); }
	virtual void onChange() = 0;
};

class C : public virtual Notifier
{
protected:
	void start() { std::cout << "C::start()" << std::endl; onChange(); }
	virtual void onChange() = 0;
};

class App : private A,B,C
{
public:
	App():A(),C(),B(){}

	virtual void onChange()
	{
		std::cout << "On change" << std::endl;
	}

	virtual void onChange(int i)
	{
		std::cout << "On change integer" << std::endl;
	}

	void s()
	{
		customA();
		/*using A::start;
		using B::start;
		using C::start;*/

		std::cout << "App::start()" << std::endl;

		//start();

		A::start();
		B::start();
		C::start();
	};
};


class Base
{
public:
	virtual void start() { std::cout << "Base::start()" << std::endl; }
};

class Base2
{
public:
	virtual void start() { std::cout << "Base2::start()" << std::endl; }
};

class Derived : public Base, public Base2
{
public:
	virtual void start() 
	{
		Base::start();
		std::cout << "Derived::start()" << std::endl;
		//start();
	}
};