#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/making-a-large-island/

class Solution
{
    vector<int> par, size;

    int find(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }

        if (size[a] < size[b])
        {
            size[b] += size[a];
            par[a] = b;
        }
        else
        {
            size[a] += size[b];
            par[b] = a;
        }
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size(), maxSize = 0;
        par.resize(n * m + 1, -1);
        size.resize(n * m + 1, 1);
        const vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {

                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dir[d].first;
                        int nj = j + dir[d].second;
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] != 1)
                        {
                            continue;
                        }

                        int node = i * m + j;
                        int adjNode = ni * m + nj;
                        Union(node, adjNode);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                unordered_set<int> neighbourSize;
                if (grid[i][j] == 0)
                {

                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dir[d].first;
                        int nj = j + dir[d].second;
                        if (ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] != 1)
                        {
                            continue;
                        }

                        int adjNode = ni * m + nj;
                        neighbourSize.insert(find(adjNode));
                    }
                }

                int allNeighbourSize = 0;
                for (auto it : neighbourSize)
                {
                    allNeighbourSize += size[it];
                }

                maxSize = max(maxSize, 1 + allNeighbourSize);
            }
        }

        for (int i = 0; i < n * m; i++)
        {
            maxSize = max(maxSize, size[i]);
        }

        return maxSize;
    }
};

int main(){
    

    return 0;
}