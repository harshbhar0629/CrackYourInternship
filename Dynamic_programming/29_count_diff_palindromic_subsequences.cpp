#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-different-palindromic-subsequences/

#define ll long long int
class Solution
{
    const ll mod = 1e9 + 7;
    int dp[1005][1005];
    string s;

    ll f(int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        ll ans = 0;
        if (s[i] == s[j])
        {
            ans = (2 * f(i + 1, j - 1)) % mod;
            int l = i + 1, r = j - 1;
            while (l <= r and s[l] != s[i])
                l++;
            while (l <= r and s[r] != s[j])
                r--;
            if (l < r)
                ans = (ans - f(l + 1, r - 1) + mod) % mod;
            else if (l == r)
                ans++;
            else
                ans += 2;
        }
        else
        {
            ans = ((f(i + 1, j) + f(i, j - 1)) % mod - f(i + 1, j - 1) + mod) % mod;
        }

        return dp[i][j] = ans;
    }

public:
    int countPalindromicSubsequences(string s)
    {
        memset(dp, -1, sizeof dp);
        this->s = s;
        return f(0, s.size() - 1);
    }
};

int main(){
    

    return 0;
}