#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int sum = neededTime[i];
            int maxi = neededTime[i];
            while (j < n and colors[i] == colors[j])
            {
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            i = j - 1;
            ans += sum - maxi;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}