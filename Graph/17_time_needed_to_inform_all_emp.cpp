#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<list<int>> gp(n, list<int>());
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                gp[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> qu;
        qu.push({headID, 0});
        int maxTime = 0;
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            int node = curr.first;
            int time = curr.second;
            maxTime = max(maxTime, time);

            for (auto it : gp[node])
            {
                qu.push({it, time + informTime[node]});
            }
        }

        return maxTime;
    }
};

int main(){
    

    return 0;
}