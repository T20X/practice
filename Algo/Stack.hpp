#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <vector>
#include <iostream>

namespace datastructures
{

	template <typename T>
	class DoubleStack
	{
	public:
		DoubleStack(size_t size)
		 :m_size(size),
		  m_leftIndex(0),
		  m_rightIndex(m_size-1)
		{
			m_array.resize(m_size);
		}

		T& peekFirst()
		{
			if (m_lefIndex)
			{
				return m_array[m_leftIndex-1];
			}

			throw std::exception("empty first stack");
		}

		void pushFirst(const T& v)
		{
			if (m_leftIndex > m_rightIndex)
				throw std::exception("first stack overflow");

			m_array[m_leftIndex] = v;
			m_leftIndex++;
		}

		T popFirst()
		{
			if (m_leftIndex)
			{
				m_leftIndex--;
				return m_array[m_leftIndex];
			}

			throw std::exception("empty first stack");
		}

		T& peekSecond()
		{
			if (m_rightIndex < (m_size-1))
			{
				return m_array[m_rightIndex+1];
			}

			throw std::exception("empty second stack");
		}

		void pushSecond(const T& v)
		{
			if (m_leftIndex > m_rightIndex)
				throw std::exception("first stack overflow");

			m_array[m_rightIndex] = v;
			m_rightIndex--;
		}

		T popSecond()
		{
			if (m_rightIndex < (m_size-1))
			{
				m_rightIndex++;
				return m_array[m_rightIndex];
			}

			throw std::exception("empty stack stack");
		}

	private:		
		size_t m_size;
		size_t m_leftIndex;
		size_t m_rightIndex;
		std::vector<T> m_array;
	};

	void doubleStack()
	{
		try
		{
			int N = 0;

			//Test 1
			N = 5;
			DoubleStack<int> s(N);
			for (int i = 0; i < N/2; i++)
			{
				s.pushFirst(i);		
				s.pushSecond(N-i-1);
			}

			std::cout << "FirstStack:" << std::endl;
			for (int i = 0; i < N/2; i++)
			{
				std::cout << s.popFirst() << std::endl;
			}

			std::cout << "SecondStack:" << std::endl;
			for (int i = 0; i < N/2; i++)
			{
				std::cout << s.popSecond() << std::endl;
			}
		}
		catch (const std::exception& e)
		{
			std::cout << std::endl << e.what() 
				      << std::endl;
		}
	}
}

#endif // _STACK_HPP_