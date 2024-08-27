#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combinations/

class Solution
{
    vector<vector<int>> ans;
    void f(int val, int n, int k, vector<int> &v)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        if (val > n)
            return;

        for (int i = val + 1; i <= n; i++)
        {
            v.push_back(i);
            f(i, n, k, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        f(0, n, k, v);
        return ans;
    }
};

int main(){
    

    return 0;
}