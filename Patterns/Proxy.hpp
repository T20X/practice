#ifndef _PROXY_HPP_
#define _PROXY_HPP_

#include <iostream>

/*Typically, one instance of the complex object and multiple proxy objects are created,
all of which contain a reference to the single original complex object.
Any operations performed on the proxies are forwarded to the original object. 
Once all instances of the proxy are out of scope, the complex object's memory may be deallocated.*/

/*The proxy design pattern allows you to provide an interface to other objects by creating a wrapper class as the proxy.
The wrapper class, which is the proxy, can add additional functionality to the object of interest without changing the object's code.
Below are some of the common examples in which the proxy pattern is used*/


/*
DIFFRENCE TO PROXY:
----------------------
The wrapper pattern (aka the adapter pattern) takes one interface and adapts it to the other.
A proxy implements an interface for the purpose of providing access to something else (usually something big).
A good example is remote procedure calls.
}*/

class IJob
{
public:
	virtual ~IJob() = 0;
	virtual void allJob() const = 0;
};

inline IJob::~IJob() {}

class ComplexObject : IJob
{
public:
	void funcA() {}
	void funcB() {}
	void allJob() const { std::cout << "Proxy: ComplexObject->func()" << std::endl; }
};

class Proxy : public IJob
{
public:
	Proxy(const ComplexObject& o):m_o(o) {}
	void allJob() const { m_o.allJob(); }

private:
	const ComplexObject& m_o;
};

namespace proxy
{
	inline void go()
	{
		ComplexObject o;
		Proxy proxy(o);
		proxy.allJob();
	}
}

#endif // _PROXY_HPP_
