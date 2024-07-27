#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution
{

    bool isPossible(vector<int> &v, int k, int mid)
    {
        int cnt = 1;
        int m = mid;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] <= m)
            {
                m -= v[i];
            }
            else
            {
                cnt++;
                m = mid - v[i];
            }
        }

        return cnt <= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            lo = max(lo, nums[i]);
            hi += nums[i];
        }

        int ans = 0;
        while (lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if (isPossible(nums, k, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}