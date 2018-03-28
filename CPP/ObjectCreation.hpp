#pragma once

#include <boost/shared_ptr.hpp>
#include <iostream>

namespace objecreation
{
	class Pure
	{
	public:
		virtual void a() = 0;
        virtual void f(int i)
        {
            std::cout << "Pure::f()" << i << std::endl;
        }   
	};

	inline void Pure::a()
	{
	}

	class PureDerived : public Pure
	{
	public:
		void a() { Pure::a();}
		void f(float i) 
        {
            std::cout << "PureDerived::f() " << i <<  std::endl;
        }
	};

	class OnlyHeap
	{
	public:
		static boost::shared_ptr<OnlyHeap> safeCreate() 
		{
			return boost::shared_ptr<OnlyHeap>(new OnlyHeap()); 		
		}
		
		~OnlyHeap() { std::cout << "OnlyHeap::destructor" << std::endl; }
		
	private:
		OnlyHeap() { std::cout << "OnlyHeap::constructor" << std::endl;}	
        
		OnlyHeap(const OnlyHeap& o);
		OnlyHeap& operator=(const OnlyHeap& o);
	};

	void test()
	{        
		PureDerived p;
        Pure& pBase = p;
        p.f(static_cast<int>(12.8));
        pBase.f(12.9);
		//380971734741
		//0959099466
		//OnlyHeap* o = new OnlyHeap();
		{
			boost::shared_ptr<OnlyHeap> ptr = OnlyHeap::safeCreate();
			//OnlyHeap* o  = new OnlyHeap();
			//ptr->~OnlyHeap();
		}
	}
}
