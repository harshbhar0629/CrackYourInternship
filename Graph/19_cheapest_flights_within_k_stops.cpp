#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#define f first
#define s second
#define pi pair<int, int>
#define ppi pair<int, pi>
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<list<pi>> graph(n, list<pi>());
        for (auto &f : flights)
        {
            graph[f[0]].emplace_back(f[1], f[2]);
        }

        queue<ppi> qu;
        qu.push({0, {0, src}});
        vector<int> dis(n, 1e8);
        dis[src] = 0;

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            int _k = curr.f;
            int wt = curr.s.f;
            int node = curr.s.s;

            for (auto it : graph[node])
            {
                if (wt + it.s < dis[it.f] and _k <= k)
                {
                    dis[it.f] = wt + it.s;
                    qu.push({_k + 1, {dis[it.f], it.f}});
                }
            }
        }

        return (dis[dst] == 1e8) ? -1 : dis[dst];
    }
};

int main(){
    

    return 0;
}