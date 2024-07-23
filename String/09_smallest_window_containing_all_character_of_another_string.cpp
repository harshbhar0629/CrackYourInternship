#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string t)
    {
        vector<int> ft(26, 0);
        for (auto ch : t)
        {
            ft[ch - 'a']++;
        }

        int charComeInT = 0;
        int i = 0, j = 0, mini = 1e8;
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {

            if (ft[s[i] - 'a'] > 0)
            {
                charComeInT++;
            }
            --ft[s[i] - 'a'];

            while (charComeInT == t.size())
            {
                // cout<<j<<" "<<i<<" \n";
                ft[s[j] - 'a']++;
                if (ft[s[j] - 'a'] > 0)
                {
                    --charComeInT;
                }
                if (i - j + 1 < mini)
                {
                    mini = i - j + 1;
                    idx = j;
                }
                j++;
            }
        }

        return (mini == 1e8) ? "-1" : s.substr(idx, mini);
    }
};

int main(){
    

    return 0;
}