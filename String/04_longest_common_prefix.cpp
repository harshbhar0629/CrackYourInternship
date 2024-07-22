#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string ans = "";
        for (int i = 0; i < min(strs[0].size(), strs.back().size()); i++)
        {
            if (strs[0][i] != strs.back()[i])
            {
                return ans;
            }
            ans += strs[0][i];
        }

        return ans;
    }
};

int main(){
    

    return 0;
}