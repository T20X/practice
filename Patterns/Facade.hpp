#ifndef _FACADE_HPP_
#define _FACADE_HPP_

#include <iostream>

/*The facade only exposes the existing functionality from a different perspective.
The mediator "adds" functionality because it combines different existing functionality to create a new one*/

class SystemA
{
public:
	void a();
};

inline void SystemA::a() {}

class SystemB
{
public:
	void b();
};

inline void SystemB::b() {}

class Facade
{
public:
	void all()
	{
		m_a.a();
		m_b.b();

		std::cout << "Facade::all" << std::endl;
	}

private:
	SystemA m_a;
	SystemB m_b;
};

namespace facade
{
	inline void go()
	{
		Facade f;
		f.all();
	}
}

#endif // _FACADE_HPP_