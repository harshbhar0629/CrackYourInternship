#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

class Solution
{
    vector<vector<string>> ans;
    bool isPalindrome(int i, int j, const string &s)
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

    void f(int i, vector<string> &v, const string &s)
    {
        if (i == s.size())
        {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(i, j, s))
            {
                v.push_back(s.substr(i, j - i + 1));
                f(j + 1, v, s);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> allPalindromicPerms(string S)
    {
        vector<string> v;
        f(0, v, S);
        return ans;
    }
};

int main(){
    

    return 0;
}