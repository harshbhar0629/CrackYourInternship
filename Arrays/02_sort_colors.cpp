#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-colors/description/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1, mid = 0;

        while (mid <= hi)
        {
            if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[mid], nums[lo]);
                lo++, mid++;
            }
            else if (nums[hi] == 2)
            {
                hi--;
            }
            else
            {
                swap(nums[mid], nums[hi]);
            }
            // cout<<lo<<" "<<mid<<" "<<hi<<"\n";
        }
    }
};

int main(){
    

    return 0;
}