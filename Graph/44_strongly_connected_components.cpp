#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
    void dfs(int src, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[src] = 1;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(src);
    }

    void dfs1(int src, vector<int> &vis, vector<list<int>> &gp)
    {
        vis[src] = 1;
        for (auto it : gp[src])
        {
            if (!vis[it])
            {
                dfs1(it, vis, gp);
            }
        }
    }

public:
    int kosaraju(int n, vector<vector<int>> &adj)
    {
        vector<int> vis(n, 0);
        stack<int> st;
        // store in stack those who are not in cycle
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        // now reverse the edges or direction of graph
        vector<list<int>> graph(n, list<int>());
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                graph[it].push_back(i);
            }
        }

        // process all leaf nodes
        int cnt = 0;
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            if (!vis[curr])
            {
                dfs1(curr, vis, graph);
                cnt++;
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}