#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/majority-element/description/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int ele = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (ele == nums[i])
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    ele = nums[i];
                    count = 1;
                    continue;
                }
                count--;
            }
        }
        return ele;
    }
};

int main(){
    

    return 0;
}