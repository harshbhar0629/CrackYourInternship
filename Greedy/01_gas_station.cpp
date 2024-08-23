#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/gas-station/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int deficiency = 0, amount = 0, idx = 0;
        for (int i = 0; i < n; i++)
        {
            amount += gas[i];
            amount -= cost[i];
            if (amount < 0)
            {
                idx = i + 1;
                deficiency += amount;
                amount = 0;
            }
        }

        if (deficiency + amount < 0)
        {
            return -1;
        }
        return idx;
    }
};

int main(){
    

    return 0;
}