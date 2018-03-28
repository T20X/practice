#pragma once

#include <stack> 
#include <vector> 
#include <iostream> 
#include <algorithm> 

namespace dynamic
{
    using namespace std;

    int minCoinSum(const std::vector<int>& coins, int sum)
    {
        vector<int> allSolutions;
        allSolutions.push_back(0);

        for (int i = 1; i <= sum; i++)
            allSolutions.push_back(-1);

        for (int i = 1; i <= sum; i++)
        {
            for (vector<int>::const_iterator it = coins.begin(); it != coins.end();++it)
            {
                if (*it <= i && (allSolutions[i-*it] + 1 < allSolutions[i] || allSolutions[i] < 0))
                    allSolutions[i] = allSolutions[i-*it] + 1;
            }
        }

        return allSolutions[sum];
    }

    void testMinCoinSum()
    {
        vector<int> coins;
        coins.push_back(1);
        coins.push_back(3);
        coins.push_back(5);

        cout << "Min number of coins : " << minCoinSum(coins,111) << endl;
    }
}