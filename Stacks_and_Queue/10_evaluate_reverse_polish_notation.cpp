#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description

class Solution
{
    int getVal(string s)
    {
        int res = 0;
        int i = 0;
        while (i < s.size())
        {
            res = res * 10 + s[i] - '0';
            i++;
        }

        return res;
    }

    int solve(int a, int b, char ch)
    {
        if (ch == '+')
        {
            return a + b;
        }
        if (ch == '-')
        {
            return a - b;
        }
        if (ch == '*')
        {
            return a * b;
        }
        return a / b;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto it : tokens)
        {
            if (it.size() == 1 and (it[0] == '-' || it[0] == '+' || it[0] == '*' || it[0] == '/'))
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = solve(a, b, it[0]);
                st.push(ans);
            }
            else
            {
                bool isNeg = false;
                if (it[0] == '-')
                {
                    isNeg = true;
                }
                string s = !isNeg ? it : it.substr(1);
                int val = getVal(s) * (isNeg ? -1 : 1);
                st.push(val);
            }
        }

        return st.top();
    }
};

int main(){
    

    return 0;
}