#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i = 0, j = 0, maxi = 0, ans = 0;
        unordered_map<int, int> mp;
        while (j < s.size())
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if ((j - i + 1) - maxi > k)
            {
                mp[s[i++]]--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}