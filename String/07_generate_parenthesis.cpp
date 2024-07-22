#include <bits/stdc++.h>
using namespace std;

// https : // leetcode.com/problems/generate-parentheses/description/

class Solution
{
    vector<string> ans;
    void f(int open, int close, int n, string &s)
    {
        if (open == n and close == n)
        {
            ans.push_back(s);
            return;
        }
        if (open > n || close > n)
        {
            return;
        }

        if (open > close)
        {
            s += ')';
            f(open, close + 1, n, s);
            s.pop_back();
        }
        if (open + 1 <= n)
        {
            s += '(';
            f(open + 1, close, n, s);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        string s = "";
        f(0, 0, n, s);
        return ans;
    }
};

int main()
{

    return 0;
}