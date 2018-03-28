#include <iostream>
#include <boost/shared_ptr.hpp>

#include "Proxy.hpp"
#include "Facade.hpp"
#include "Decorator.hpp"
#include "CRTP.hpp"
#include "OOP_terms.hpp"

using namespace std;

int main()
{
	/*proxy::go();
	facade::go();
	decorator::go();*/

	crtp::test();
	getchar();
}