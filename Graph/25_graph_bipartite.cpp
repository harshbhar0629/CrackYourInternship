#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/bipartite-graph/1

class Solution
{

    bool bfs(int src, vector<int> &colors, vector<int> adj[])
    {
        queue<int> qu;
        qu.push(src);
        colors[src] = 0;

        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            for (auto it : adj[curr])
            {
                if (it == curr)
                    continue;
                if (colors[it] == -1)
                {
                    colors[it] = !colors[curr];
                    qu.push(it);
                }
                else if (colors[it] == colors[curr])
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(int n, vector<int> adj[])
    {
        vector<int> colors(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
            {
                if (bfs(i, colors, adj) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    

    return 0;
}