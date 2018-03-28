#ifndef _OOP_TERMS_HPP_
#define _OOP_TERMS_HPP_

#include <vector>

// Composition
class Car
{
private:
  // Car is the owner of carburetor.
  // Carburetor is created when Car is created,
  // it is destroyed when Car is destroyed.
  int carb;

};

// Aggregation
class Pond
{
private:

  // Pond is not the owner of ducks,
  // it has references on other ducks managed somewhere else
  std::vector<int*> ducks;
};

#endif // _OOP_TERMS_HPP_