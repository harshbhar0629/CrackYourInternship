#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution
{

    bool dfs(int s, vector<int> &vis, vector<int> adj[])
    {
        vis[s] = 1;
        for (auto it : adj[s])
        {
            if (vis[it] == 0)
            {
                bool b = dfs(it, vis, adj);
                if (b)
                    return b;
            }
            else if (vis[it] == 1)
                return true;
        }
        vis[s] = 2;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    

    return 0;
}