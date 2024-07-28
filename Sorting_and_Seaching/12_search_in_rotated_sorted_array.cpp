#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        int ans = 0;

        while (lo <= hi)
        {
            int m = (lo + hi) / 2;
            if (nums[lo] <= nums[m])
            {
                // we r on increasing array
                if (target >= nums[lo] and target <= nums[m])
                {
                    hi = m - 1;
                    ans = m;
                }
                else
                {
                    lo = m + 1;
                }
            }
            else
            {
                // we r on decreaing array
                if (nums[m] <= target and target <= nums[hi])
                {
                    lo = m + 1;
                    ans = m;
                }
                else
                {
                    hi = m - 1;
                }
            }
        }

        return (nums[ans] == target) ? ans : -1;
        ;
    }
};

int main(){
    

    return 0;
}