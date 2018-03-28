#pragma once

#include <iostream>

namespace crtp
{

    class VeryBase
    {
    public:
        virtual void doJob() {std::cout << "very base" << std::endl;}
    };

template <typename derived>
	class base 
	{
	public:
		void doJob()
		{
			static_cast<derived*>(this)->doJobImpl();
		}
	private:
		void doJobImpl()
		{
		}
	};

	class D1 : public base<D1>
	{
    public:
        void doJobImpl()
        {
            std::cout << "D1 do job" << std::endl;
        }
	};

	template <typename T>
	void dispatch(base<T>& v)
	{
		v.doJob();
	}

	void test()
	{
		D1 d;
        //base<D1>& b = d;
        //VeryBase& v = b;
		dispatch(d);
	}
};