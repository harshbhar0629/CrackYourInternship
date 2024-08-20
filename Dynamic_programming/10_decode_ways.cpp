#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/decode-ways/

class Solution
{
    int dp[105];
    bool STOI(string s)
    {
        if (s.size() == 1)
        {
            return s[0] != '0';
        }
        return ((s[0] - '0') * 10 + (s[1] - '0')) <= 26;
    }

    int f(int i, string &s)
    {
        if (i == s.size() || s[i] == '0')
        {
            return 0;
        }
        if (i == s.size() - 1)
        {
            if (s[i] == '0')
            {
                return 0;
            }
            return 1;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        if (i == s.size() - 2)
        {
            bool canWeMakeCharacter = STOI(s.substr(i, 2));
            return dp[i] = canWeMakeCharacter + f(i + 1, s);
        }

        bool canWeMakeCharacter = STOI(s.substr(i, 2));
        return dp[i] = (canWeMakeCharacter ? f(i + 2, s) : 0) + f(i + 1, s);
    }

public:
    int numDecodings(string s)
    {
        memset(dp, -1, sizeof dp);
        return f(0, s);
    }
};

int main(){
    

    return 0;
}