#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/evaluate-division/

class Solution
{

    void buildGraph(vector<vector<string>> &eqn, vector<double> &val, unordered_map<string, unordered_map<string, double>> &graph)
    {
        int n = eqn.size();
        for (int i = 0; i < n; i++)
        {
            auto divisor = eqn[i][0];
            auto dividend = eqn[i][1];
            graph[divisor][dividend] = val[i] * 1.0;
            graph[dividend][divisor] = 1.0 / val[i];
        }
    }

    void dfs(unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &vis, double &res, double temp, string src, string &dest)
    {
        if (vis.count(src) > 0)
        {
            return;
        }
        if (src == dest)
        {
            res = temp;
            return;
        }

        vis.insert(src);
        for (auto it : graph[src])
        {
            // it gives you a pair of pair<string, double>
            dfs(graph, vis, res, temp * it.second, it.first, dest);
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &eqn, vector<double> &val, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> graph;
        buildGraph(eqn, val, graph);

        vector<double> ans;
        for (auto it : queries)
        {
            auto divisor = it[0];
            auto dividend = it[1];
            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
            {
                ans.push_back(-1.0);
            }
            else
            {
                unordered_set<string> vis;
                double res = -1.0, temp = 1.0;
                dfs(graph, vis, res, temp, divisor, dividend);
                ans.push_back(res);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}