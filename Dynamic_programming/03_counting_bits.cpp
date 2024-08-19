#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};

int main(){
    

    return 0;
}