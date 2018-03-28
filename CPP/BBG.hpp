#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*write a function to compare 2 strings of the same length,
find the number of different chars. e.g. myCompare('bond','debt') = 2 
myCompare('xxxx','yyyy') = 2 the 2 input parameters are const*/

static size_t ASCII_MAX_N = 128;
static int diffCharsN(const std::string& s1, 
                      const std::string& s2)
{
    size_t lenS1 = s1.size();
    size_t lenS2 = s2.size();
    if (lenS1 != lenS2) 
        return -1;

    vector<int> t1; 
    t1.resize(ASCII_MAX_N,0);

    vector<int> t2; 
    t2.resize(ASCII_MAX_N,0);

    for(int i = 0; i < lenS1; i++)
    {
        cout << "i: " << i << " s1: " << (int)s1[i] << " s2: " << (int)s2[i] << endl;
        t1[s1[i]] = 1;
        t2[s2[i]] = 1;
    }

    int N = 0;
    for (int i = 0; i < ASCII_MAX_N; i++)
    {
        if ((t1[i]+t2[i]) == 1)
            N++;
    }

    return N;
}
static void testdiffCharsN()
{
    string s1("bond");
    string s2("debt");
    cout << s1 << " diff chars with " << s2 << " : " << diffCharsN(s1,s2);

}


static bool sameNChars(int N, const std::string& s)
{    
    size_t len = s.size();
    if (len < N) return false;

    for (int i = 1, f = 0 , t = 0; i < len; i++)
    {
        if (s[i] == s[i-1]) t=i; else f=i;  
        if ((t - f) == (N - 1)/*pos*/)
            return true;        
    }

    return false;
}

static void testSame3Chars()
{
    string s("asdasdddffff");
    cout << s << "  " << sameNChars(5, s)  << endl;

    string s1("aasdasd122111111111131134");
    cout << s1 << " " << sameNChars(5, s1) << endl;
}


/*Rearrange the elements of an array so that all zeroes are at the end of the array,
while preserving the ordering of the nonzero elements. */

static void rearange(int* input, int N)
{
    int zeroNum = 0;
    for (int i = 0;  i < N; i++)
    {
        if (input[i] == 0)
        {
            zeroNum++;
        }
        else
        {
            input[i - zeroNum] = input[i];
        }
    }

    if (!zeroNum) return;
    for (int i = (N-1); (N - i) <= zeroNum; i--)
        input[i] = 0;        
}

static void testRearange()
{
    int i1[] = {12,23,0,23,5,6,10,10,23,10,10,10,10,5,9};
    rearange(i1,15);
    for (int i = 0; i < 15; i++)
    {
        cout << i1[i] << " ";
    }
}
