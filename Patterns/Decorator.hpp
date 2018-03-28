#ifndef _DECORATOR_HPP_
#define _DECORATOR_HPP_

#include <iostream>


/*The decorator pattern is an alternative to subclassing. Subclassing adds behavior at compile time, 
and the change affects all instances of the original class; decorating can provide new behavior at run-time for individual objects.
This difference becomes most important when there are several independent ways of extending functionality.
In some object-oriented programming languages, classes cannot be created at runtime, and it is typically not possible to predict, 
at design time, what combinations of extensions will be needed. This would mean that a new class would have to be made for every possible combination. 
By contrast, decorators are objects, created at runtime, and can be combined on a per-use basis. 
The I/O Streams implementations of both Java and the .NET Framework incorporate the decorator pattern*/

class IComplexObject
{
public:
	virtual ~IComplexObject() {}
	virtual void a() = 0;
	virtual void b() = 0;
};

class Decorated : public IComplexObject
{
public:
	void a() {}
	void b() {}
};

class Decorator : public IComplexObject
{
public:
	Decorator(Decorated& o):m_decorated(o) {}

	void a() 
	{
		std::cout << "Decorator::a()" << std::endl; 
		m_decorated.a();
	}

	void b()
	{ 
		m_decorated.b();
	}

private:
	Decorated& m_decorated;
};

namespace decorator
{
	inline void go()
	{
		Decorated d;
		Decorator o(d);
		o.a();
	}
}

#endif // _DECORATOR_HPP_