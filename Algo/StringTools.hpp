#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>

class StringTools
{
public:
	static char* reverse(char* input)
	{
        if (!input) return 0;

		size_t len = strlen(input);
		size_t half = len/2;
		for (size_t l = 0, r = (len - 1); l < half; l++, r--)
		{
			char temp = input[l];
			input[l] = input[r];
			input[r] = temp;
		}

        return input;
	}

	static void testReverse()
	{
		char* i1 = "a";
		reverse(i1);
		std::cout << i1 << std::endl;

		char i2[] = "ab";
		reverse(i2);
		std::cout << i2 << std::endl;

		char i3[] = "acb";
		reverse(i3);
		std::cout << i3 << std::endl;

		char i4[] = "2a5cb";
		reverse(i4);
		std::cout << i4 << std::endl;
	}


};