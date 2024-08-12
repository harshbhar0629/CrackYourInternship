#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution
{
public:
    void dfs(vector<int> adj[], vector<int> &vis, int V, int node, int prev, bool &check)
    {
        vis[node] = 1;
        for (int i : adj[node])
        {
            if (i == prev)
            {
                continue;
            }
            else if (vis[i])
            {
                check = true;
            }
            else
            {
                dfs(adj, vis, V, i, node, check);
            }
        }
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool check = false;
                dfs(adj, vis, V, i, -1, check);
                if (check)
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