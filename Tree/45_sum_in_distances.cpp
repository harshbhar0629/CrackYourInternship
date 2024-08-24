#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution
{
    vector<list<int>> graph;
    vector<int> cnt, res;
    void dfs(int s, int p = -1)
    {
        for (auto it : graph[s])
        {
            if (it == p)
            {
                continue;
            }
            dfs(it, s);
            cnt[s] += cnt[it];
            res[s] += cnt[it] + res[it];
        }
        cnt[s]++;
    }

    void dfs1(int s, int n, int p = -1)
    {
        for (auto it : graph[s])
        {
            if (p == it)
            {
                continue;
            }
            res[it] = n - cnt[it] + res[s] - cnt[it];
            dfs1(it, n, s);
        }
    }
    // formula first find the answer from zero so we have atleast one answer and cnt of nodes
    // res[i] ka answer jo uske upr h jitni node wo +1 honge or jo neche h wo -1
    // inc = +1 case => upr wale node niklenge total_node - curr_node+curr_all_child
    // dec -1 case => parent ka answer m s curr cnt of all child

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        graph.resize(n, list<int>());
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        cnt.resize(n, 0);
        res.resize(n, 0);
        dfs(0);
        // for(int i=0; i<n; i++){
        //     cout<<cnt[i]<<" ";
        // }cout<<"\n";
        // for(int i=0; i<n; i++){
        //     cout<<res[i]<<" ";
        // }
        dfs1(0, n);
        // cout<<"\n";
        // for(int i=0; i<n; i++){
        //     cout<<res[i]<<" ";
        // }
        return res;
    }
};

int main(){
    

    return 0;
}