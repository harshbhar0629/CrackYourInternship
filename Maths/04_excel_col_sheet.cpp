#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution
{
public:
    string convertToTitle(int n)
    {
        vector<char> v = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        string ans = "";

        while (n > 0)
        {
            n--;
            int idx = n % 26;
            ans += v[idx];

            n /= 26;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    

    return 0;
}