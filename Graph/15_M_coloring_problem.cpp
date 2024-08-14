#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution
{
    int n, m;

    bool isPossible(int newColor, int src, vector<int> &colors, bool graph[101][101])
    {
        for (int i = 0; i < n; i++)
        {
            if (i != src and graph[src][i] == 1 and colors[i] == newColor)
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(bool graph[101][101], vector<int> &color, int src)
    {
        if (src == n)
        {
            return true;
        }

        for (int i = 1; i <= m; i++)
        {
            if (isPossible(i, src, color, graph))
            {
                color[src] = i;
                if (dfs(graph, color, src + 1))
                {
                    return true;
                }
                color[src] = 0;
            }
        }

        return false;
    }

public:
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        this->n = n;
        this->m = m;
        vector<int> color(n, 0);
        if (dfs(graph, color, 0))
        {
            return true;
        }

        return false;
    }
};

int main(){
    

    return 0;
}