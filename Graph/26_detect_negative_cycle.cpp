#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dis(n, 1e7);
        dis[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (auto &it : edges)
            {
                int u = it[0], v = it[1], wt = it[2];
                if (dis[u] != 1e7 and dis[v] > dis[u] + wt)
                {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            if (dis[v] > dis[u] + wt)
            {
                return 1;
            }
        }

        return 0;
    }
};

int main(){
    

    return 0;
}