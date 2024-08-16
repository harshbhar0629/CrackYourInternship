#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        unordered_map<char, vector<char>> gp;
        unordered_map<char, int> indegree;

        for (int i = 0; i < N; i++)
        {
            for (int it : dict[i])
            {
                gp[it] = {};
                indegree[it] = 0;
            }
        }

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < min(dict[i].size(), dict[i + 1].size()); j++)
            {
                if (dict[i][j] != dict[i + 1][j])
                {
                    gp[dict[i][j]].push_back(dict[i + 1][j]);
                    indegree[dict[i + 1][j]]++;
                    break;
                }
            }
        }

        queue<char> qu;
        for (auto it : indegree)
        {
            if (it.second == 0)
            {
                qu.push(it.first);
            }
        }

        string res = "";
        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            res += curr;

            if (res.size() == K)
            {
                break;
            }

            for (auto it : gp[curr])
            {
                if (--indegree[it] == 0)
                {
                    indegree.erase(it);
                    qu.push(it);
                }
            }
        }

        return res;
    }
};

int main(){
    

    return 0;
}