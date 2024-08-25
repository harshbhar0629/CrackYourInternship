#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-pairs/

class Solution
{
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
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

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_map<string, int> mp;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            reverse(word.begin(), word.end());
            mp[word] = i;
        }

        vector<vector<int>> ans;
        if (mp.find("") != mp.end())
        {
            for (int i = 0; i < n; i++)
            {
                if (words[i] == "")
                    continue;
                if (isPalindrome(words[i]))
                {
                    ans.push_back({mp[""], i});
                }
            }
        }
        // cout<<"Hey";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                string left = words[i].substr(0, j);
                // cout<<"Print";
                string right = words[i].substr(j);
                // cout<<left<<" "<<right<<"\n";
                if (mp.find(left) != mp.end() and isPalindrome(right) and mp[left] != i)
                {
                    ans.push_back({i, mp[left]});
                }
                if (mp.find(right) != mp.end() and isPalindrome(left) and mp[right] != i)
                {
                    ans.push_back({mp[right], i});
                }
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}