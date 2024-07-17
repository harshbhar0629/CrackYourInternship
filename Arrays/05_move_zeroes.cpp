#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/move-zeroes/description/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        while (i < n)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }

        for (; j < n; j++)
        {
            nums[j] = 0;
        }
    }
};

int main()
{

    return 0;
}