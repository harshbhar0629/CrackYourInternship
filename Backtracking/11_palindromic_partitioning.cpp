#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution
{
    vector<vector<string>> ans;

    bool isPalindrome(const string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    void f(int i, const string &s, vector<string> &v)
    {
        if (i == s.size())
        {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                v.push_back(s.substr(i, j - i + 1));
                f(j + 1, s, v);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        f(0, s, v);

        return ans;
    }
};

int main(){
    

    return 0;
}