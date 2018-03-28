#ifndef _BYTES_HPP_
#define _BYTES_HPP_

/*
Little-endian[edit]
Atomic element size 8-bit[edit]
address increment 1-byte (octet)
increasing addresses  →
…	0Dh	0Ch	0Bh	0Ah	…
The least significant byte (LSB) value, 0Dh, is at the lowest address. The other bytes follow in increasing order of significance

in x86 call stack grows downward

Downwards is more common; it's the case in x86, PowerPC, MIPS, SPARC, EE, and the Cell SPU
*/

#include <iostream>
#include <string>
#include <string> 
#include <limits> 

int f()
{
	int t = 2 +3;
	return t;
}

/*count 1's in an integer*/
inline int count(unsigned int n)
{	
	unsigned c =int();
	size_t l = sizeof(int)*8;
	for (int i = 0; i < l; i++)	
		if ((1<<i) & n) c++;		
	
	std::cout << "Int: " << n << " | 1s bits: " << c << std::endl;
	return c;
}

inline int setNthBit(int v, int p)
{
    int r  = v | (1 << (p - 1));
    return r;
}

inline int unsetNthBit(int v, int p)
{
    int r  = v ^ (1 << (p - 1));
    return r;
}

inline std::string displayBinary(int v)
{
   size_t bitsN = std::numeric_limits<int>::digits;
   if (std::numeric_limits<int>::is_signed)   
       bitsN++;
   
    char* str = new char[bitsN+1];    
    str[bitsN] = '\0';

    for (int i = 0; i < bitsN; i++)
    {
        size_t pos = bitsN - i - 1;
        if (v >> i & 1) str[pos] = '1';
                   else str[pos] = '0';
    }

    std::string r(str);
    delete[] str;
    return r;
}

#endif // _BYTES_HPP_