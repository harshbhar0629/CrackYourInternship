#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/knight-dialer/

#define pi pair<int, int>
#define ll long long int
class Solution
{
    const ll mod = 1e9 + 7;
    ll dp[5005][5][5];
    vector<pi> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    int f(int i, int j, int n)
    {
        // handle cases where knight going to outside the phone key-pad
        if (i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 and j != 1))
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (dp[n][i][j] != -1)
        {
            return dp[n][i][j];
        }

        ll ans = 0;
        for (int d = 0; d < 8; d++)
        {
            int ni = i + dir[d].first;
            int nj = j + dir[d].second;
            ans %= mod;
            ans += f(ni, nj, n - 1);
            ans %= mod;
        }

        return dp[n][i][j] = ans % mod;
    }

public:
    int knightDialer(int n)
    {
        memset(dp, -1, sizeof dp);
        ll ans = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans += f(i, j, n);
                ans %= mod;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}