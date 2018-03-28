#pragma once

#include <iostream>

class A2
{
public:
     void f(int i = 10) { std::cout << "A2";  }
};

class B2 : public A2
{
public:
     void f(int i = 20) { std::cout << "B2";  }
};

template <typename T>
class Policy1
{
public:
	static void a(){}
};

template <typename T>
class Policy2
{
public:
	static void b(){}
	void f();
};

template <typename T> void Policy2<T>::f()
{
	std::cout << "Policy2<standart>::f()" << std::endl;
}

template <> void Policy2<int>::f()
{
	std::cout << "Policy2<int>::f()" << std::endl;
}

template
< 
 typename T = int,
 template <class> class T1 = Policy1,
 template <class> class T2 = Policy2,
 typename T3 = Policy2<T>
>	
class Host
{
public:
	void test()
	{
		T1<T>::a();
		T2<T>::b();
		T3::b();
		T2<T>().f();
	}
};