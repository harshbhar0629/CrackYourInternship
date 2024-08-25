#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-boxes/

class Solution
{
    int dp[101][101][101];
    int f(int i, int j, int extra, vector<pair<int, int>> &grps)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j][extra] != -1)
        {
            return dp[i][j][extra];
        }

        int opt1 = (grps[i].second + extra) * (grps[i].second + extra) + f(i + 1, j, 0, grps);
        int opt2 = 0;
        for (int k = i + 1; k <= j; k++)
        {
            if (grps[k].first == grps[i].first)
            {
                opt2 = max(opt2, f(i + 1, k - 1, 0, grps) + f(k, j, extra + grps[i].second, grps));
            }
        }

        return dp[i][j][extra] = max(opt1, opt2);
    }

public:
    int removeBoxes(vector<int> &boxes)
    {
        vector<pair<int, int>> grps;
        int i = 0;
        int n = boxes.size();

        while (i < n)
        {
            int num = boxes[i];
            int cnt = 0;
            while (i < n and num == boxes[i])
            {
                i++;
                cnt++;
            }
            grps.push_back({num, cnt});
        }

        memset(dp, -1, sizeof dp);
        return f(0, grps.size() - 1, 0, grps);
    }
};

int main(){
    

    return 0;
}