#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        vector<string> v;
        stringstream ss(s);
        string t;
        while (ss >> t)
        {
            v.push_back(t);
        }

        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                ans += v[i] + " ";
            }
            else
            {
                ans += v[i];
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}