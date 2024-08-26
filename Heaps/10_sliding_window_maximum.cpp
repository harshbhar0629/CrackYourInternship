#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() and nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> res;
        res.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++)
        {
            if (dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() and nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main(){
    

    return 0;
}