#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution
{
public:
    bool isPossible(int n, int p, vector<pair<int, int>> &pre)
    {
        vector<int> indegree(n, 0);
        vector<list<int>> gp(n, list<int>());
        for (auto it : pre)
        {
            indegree[it.first]++;
            gp[it.second].push_back(it.first);
        }

        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
            }
        }

        unordered_set<int> vis;
        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            vis.insert(curr);

            for (auto it : gp[curr])
            {
                if (--indegree[it] == 0)
                {
                    qu.push(it);
                }
            }
        }

        return vis.size() == n;
    }
};

int main(){
    

    return 0;
}