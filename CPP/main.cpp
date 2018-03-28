#include <iostream>
#include "PrivateInheritance.hpp"
#include "Bytes.hpp"
#include "VT.h"
#include "HashMap.hpp"
#include "ObjectCreation.hpp"
#include "Policy.hpp"
#include "Polymorphism.hpp"
#include "Functor.hpp"
#include "STL.hpp"
#include "BBG.hpp"
#include "Exception.hpp"
#include "Map.hpp"
#include "float.hpp"

using namespace std;

void handle_unexpected()
{
    std::cerr << "Unhandled exception" << std::endl;
    _sleep(500);
}

int main()
{
  //  std::set_unexpected(handle_unexpected);
    _sleep(500);

	//count(1);
	//count(2);
	//count(256);
	//count(252136);

	//test::go();
	//objecreation::test();
	//App s;
	//s.start();

	/*Host<int,Policy1,Policy2> host;
	host.test();

	Host<double> host2;
	host2.test();*/

	//polymorphism::testReturnFromFunction();
  //  functors::basicTest();

    //testdiffCharsN();
    //testSame3Chars();
    //testRearange();
    //cout << "4th bit set to 1 in value 12  : " << setNthBit(12,5) << endl;
    //cout << "4th bit unset to 1 in value 9  : " << unsetNthBit(28,5) << endl;
    //cout << "binary 9 : " << displayBinary(9);
   // cout << getFive();
   // maps::testMap();
   // except::go();
    //math::go();

    testVectorErase();

	getchar();
}