#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>

namespace math
{
    using namespace std;

    static void fibonachi(int N, vector<unsigned int>& r)
    {
        if (N < 2)
        {
            return;
        }
              
        unsigned int p = 1;
        unsigned int pp = 0;

        r.push_back(pp);
        r.push_back(p);

        int i = 2;
        while (i < N)
        {
            int capacity = numeric_limits<unsigned int>::max() - pp;
            if (capacity < p)
            {
                cout << "Integer overflow detected at item N:" << i << endl;
                break;
            }

            r.push_back(p + pp);            
            pp = p;
            p=r[i];            
            i++;
        }
    }

    static void testFibonachi()
    {
        vector<unsigned int> r;
        fibonachi(100, r);
        copy(r.begin(), r.end(), ostream_iterator<unsigned int>(cout, " "));
    }

    void primes(int N)
    {
        for (int i = 2; i <= N; i++)
        {
            bool prime = true;
            for (int j = 2; j*j <= i; j++)
            {
                if (i%j == 0 )
                {
                    prime = false;                    
                    break;
                }
            }

            if (prime) 
                cout << i << " ";
        }
    }
}

/*
 int missingSeq(const vector& v) 
 {
 if(v.size() < 3)
 { 
 return -1;
 } 
 // first find the value by which a no is incremented to get next no in the seq int 
 d1 = v[1] - v[0];
 int d2 = v[2] - v[1]; 
 if(d1 != d2)
 { 
 // there is a missing no in 1st 3 elements 
 if(d1 < d2) { 
 // increment is d1 and there is a missing element between v1 & v2 
 return v[1] + d1; 
 } 
 else
 { // increment is d2 and there is a missing element between v0 & v1 return v[0] + d2; 
 }
 } 
 // increment is d1=d2 int d = d1; // we have found that there is no missing element between v0 and v2 // check rest of the array
 for(int i=3; i nums{1, 5, 9, 13, 17, 25, 29}; cout<
 */