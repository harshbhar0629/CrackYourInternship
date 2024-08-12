#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{

    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {
        visited[node] = 1;
        ans.push_back(node);
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                dfs(adj[node][j], adj, visited, ans);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        vector<int> ans;
        dfs(0, adj, visited, ans);
        return ans;
    }
};

int main(){
    

    return 0;
}