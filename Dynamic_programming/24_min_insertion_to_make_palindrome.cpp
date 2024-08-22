#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution
{
    string s, t;
    int dp[505][505];
    int f(int i, int j)
    {
        if (i == s.size() || j == t.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int opt1 = f(i + 1, j);
        int opt2 = f(i, j + 1);
        int opt3 = 0;
        if (s[i] == t[j])
        {
            opt3 = 1 + f(i + 1, j + 1);
        }

        return dp[i][j] = max({opt1, opt2, opt3});
    }

public:
    int minInsertions(string s)
    {
        this->s = s;
        reverse(s.begin(), s.end());
        this->t = s;
        memset(dp, -1, sizeof dp);
        return s.size() - f(0, 0);
    }
};

int main(){
    

    return 0;
}