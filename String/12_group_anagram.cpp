#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/description/
class Solution
{

    string getString(const string &s)
    {
        int v[26] = {0};
        for (auto ch : s)
        {
            v[ch - 'a']++;
        }

        string t = "";
        for (int i = 0; i < 26; i++)
        {
            int cnt = v[i];
            char ch = 'a' + i;

            while (cnt > 0)
            {
                t += ch;
                cnt--;
            }
        }

        return t;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        int n = strs.size();

        for (int i = 0; i < n; i++)
        {
            string s = getString(strs[i]);
            mp[s].push_back(strs[i]);
            cout << s << " ";
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}