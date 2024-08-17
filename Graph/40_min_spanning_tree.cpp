#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int wt, u, v;
};

class Solution
{

    vector<int> par, rank;
    int find(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        return par[x] = find(par[x]);
    }

    bool Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return true;
        }
        if (rank[a] < rank[b])
        {
            rank[b]++;
            par[a] = b;
        }
        else
        {
            rank[a]++;
            par[b] = a;
        }

        return false;
    }

public:
    int minSpanningTree(vector<Node> &edges, int n)
    {
        par.resize(n, -1);
        rank.resize(n, 1);
        sort(edges.begin(), edges.end(), [&](auto a, auto b)
             { return a.wt < b.wt; });

        int totalNode = 1;
        int totalWt = 0, i = 0;

        while (totalNode < n and i<edges.size()){
            auto curr = edges[i];
            int a = curr.u;
            int b = curr.v;
            int edgeWt = curr.wt;

            if(!Union(a, b)){
                totalWt += edgeWt;
                totalNode++;
            }
            i++;
        }

        return totalWt;
    }
};

int main()
{

    return 0;
}