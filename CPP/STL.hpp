#ifndef _STL_HPP_
#define _STL_HPP_

#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int testVectorErase()
{
    int N;
    cin >> N;
    if (N < 1 || N > pow(10.0,5.0))    
        return 0;
      
    vector<int> V;
    copy_n(istream_iterator<int>(cin), N, back_inserter(V));
      
    int x;
    cin >> x;   
    if (x < 1 || x > N)
        return 0;
    
    int a; cin >> a;
    int b; cin >> b;   
    {
        if (a < 1 || a > b)
            return 0;    
        if (b < a || b > (N-1))
            return 0;
    }
    
    V.erase(V.begin()+x-1);    
    V.erase(V.begin()+a-1, V.begin()+b-1);
    
    cout << V.size() << endl;
    copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
    
    return 0;
}

#endif // _STL_HPP_

/*

class A 
{ 
public: A()
{ 
foo();
} 
virtual void foo(int a = 10)
{ 
std::cout &lt;&lt;
"A = " &lt;&lt; a &lt;&lt;
std::endl; 
} 
};

class B : public A {

public:

B()
{ 
foo();
} 

virtual void foo(int b = 20)
{ 
std::cout &lt;&lt; "B = " &lt;&lt; b &lt;&lt; std::endl;
} };
int main() 
{ 
A* aPtr = new B();
aPtr-&gt;foo(); 
delete aPtr;
return 0; 
}  */