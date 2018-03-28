#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <set>
#include <string>

namespace maps
{
    class Citizen
    {
    public:
        Citizen(int age) :m_age(age) {}
        bool operator<(const Citizen& other) const { return m_age > other.m_age;  }

    private:
        int m_age;
    };

    void testMap()
    {
        using namespace std;
        set<Citizen> citizens;
        citizens.insert(Citizen(12));
        citizens.insert(Citizen(12));

    }
}

#endif // _MAP_HPP_


