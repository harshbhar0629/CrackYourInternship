#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        int moves = 0;
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        for (int i = 0; i < n; i++)
        {
            moves += abs(nums[i] - nums[n / 2]);
        }

        return moves;
    }
};

int main(){
    

    return 0;
}