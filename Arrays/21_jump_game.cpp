#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/jump-game/description

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return true;
        }
        if (nums[0] == 0)
        {
            return false;
        }

        int pos = nums[0];
        int maxi = 0;

        for (int i = 1; i < n; i++)
        {
            pos--;
            maxi = max(maxi, nums[i] + i);
            if (pos == 0 and i != n - 1)
            {
                if (maxi <= i)
                {
                    return false;
                }
                pos = maxi - i;
                maxi = i;
            }
        }

        return true;
    }
};

int main(){
    

    return 0;
}