#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[idx] != nums[i])
            {
                nums[idx + 1] = nums[i];
                idx++;
            }
        }

        return idx + 1;
    }
};

int main(){
    

    return 0;
}