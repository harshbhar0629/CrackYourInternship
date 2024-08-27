#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
    vector<int> cand;
    vector<vector<int>> res;
    void f(int i, vector<int> &v, int target)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }

        for (int j = i; j < cand.size(); j++)
        {
            if (j != i and cand[j - 1] == cand[j] || cand[j] > target)
                continue;
            v.push_back(cand[j]);
            f(j + 1, v, target - cand[j]);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> v;
        cand = candidates;
        sort(cand.begin(), cand.end());
        f(0, v, target);
        return res;
    }
};

int main(){
    

    return 0;
}