#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/print-anagrams-together/1

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        unordered_map<string, vector<string>> mp;
        for (auto it : string_list)
        {
            string s = it;
            sort(s.begin(), s.end());
            mp[s].push_back(it);
        }

        vector<vector<string>> ans;
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