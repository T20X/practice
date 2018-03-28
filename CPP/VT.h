#ifndef _VT_HPP_
#define _VT_HPP_

#include <iostream>

class DynamicInterface {
public:
  virtual void tick(int n) = 0;
  virtual int getvalue() = 0;
};

class DynamicImplementation : public DynamicInterface {
  int counter;

public:
  DynamicImplementation()
    : counter(0) {
  }

  virtual void tick(int n) {
    counter += n;
  }

  virtual int getvalue() {
    return counter;
  }
};

namespace vt
{
	inline void go()
	{
		DynamicInterface* o = new DynamicImplementation();
		o->tick(454);
	}
}

#endif // _VT_HPP_