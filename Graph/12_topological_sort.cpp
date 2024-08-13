#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
public:
    vector<int> topoSort(int n, vector<int> adj[])
    {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> qu;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
            }
        }

        vector<int> topo;
        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            topo.push_back(curr);

            for (auto it : adj[curr])
            {
                if (--indegree[it] == 0)
                {
                    qu.push(it);
                }
            }
        }

        return topo;
    }
};

int main()
{

    return 0;
}