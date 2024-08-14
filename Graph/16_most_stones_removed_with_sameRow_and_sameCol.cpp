#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution
{
    vector<int> rank, par;
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
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0, maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int n = maxRow + maxCol + 2;
        par.resize(n, -1);
        rank.resize(n, 1);
        unordered_map<int, int> mp;

        for (auto it : stones)
        {
            int a = it[0];
            int b = it[1] + maxRow + 1;
            Union(a, b);
            mp[a] = mp[b] = 1;
        }

        int cnt = 0;
        for (auto it : mp)
        {
            int a = it.first;
            if (find(a) == a)
            {
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};

int main(){
    

    return 0;
}