#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution
{

    bool dfs(int node, vector<bool> &vis, vector<bool> &inStack, vector<vector<int>> &gp)
    {
        if (inStack[node])
        {
            return true;
        }
        if (vis[node])
        {
            return false;
        }

        vis[node] = inStack[node] = true;
        for (auto it : gp[node])
        {
            if (dfs(it, vis, inStack, gp))
            {
                return true;
            }
        }

        inStack[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> inStack(n, false);

        for (int i = 0; i < n; i++)
        {
            dfs(i, vis, inStack, graph);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!inStack[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}