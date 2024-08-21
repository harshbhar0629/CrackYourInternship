#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/delete-and-earn/description/

class Solution
{
    int freq[10005], dp[10005];
    int f(int i)
    {
        if (i >= 10001)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int skip = f(i + 1);
        int take = freq[i] + f(i + 2);

        return dp[i] = max(skip, take);
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        memset(freq, 0, sizeof freq);
        for (auto &it : nums)
        {
            freq[it] += it;
        }

        return f(0);
    }
};

int main(){
    

    return 0;
}