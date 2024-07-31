#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/backspace-string-compare/description/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<int> st1, st2;
        for (int i = 0; i < s.size(); i++)
        {

            if (st1.size() > 0 and s[i] == '#')
                st1.pop();
            else if (s[i] != '#')
                st1.push(s[i]);
        }
        for (int i = 0; i < t.size(); i++)
        {

            if (st2.size() > 0 and t[i] == '#')
                st2.pop();
            else if (t[i] != '#')
                st2.push(t[i]);
        }
        while (st1.size() > 0 and st2.size() > 0)
        {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }
        if (st1.size() == 0 and st2.size() == 0)
            return true;
        else
            return false;
    }
};

int main(){
    

    return 0;
}