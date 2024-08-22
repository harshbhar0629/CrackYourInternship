#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray
{
public:
    vector<int> v;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        v.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            int x = nums[i] + v[i - 1];
            v.push_back(x);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return v[right];
        else
        {
            return v[right] - v[left - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main(){
    

    return 0;
}