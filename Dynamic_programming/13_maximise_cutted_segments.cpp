#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

class Solution
{
    int dp[10005];
    int f(int i, int n, vector<int> &arr)
    {
        if (i == n)
        {
            return 0;
        }
        if (i > n)
        {
            return -1e8;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = -1e8;
        for (int j = 0; j < 3; j++)
        {
            ans = max(ans, 1 + f(i + arr[j], n, arr));
        }

        return dp[i] = ans;
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> arr = {x, y, z};
        memset(dp, -1, sizeof dp);
        int ans = f(0, n, arr);
        return (ans < 0) ? 0 : ans;
    }
};

int main(){
    

    return 0;
}