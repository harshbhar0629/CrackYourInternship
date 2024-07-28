#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/minimum-swaps/1

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            p.emplace_back(nums[i], i);
        }

        sort(p.begin(), p.end());
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == p[i].second)
                continue;
            else
            {
                cnt++;
                swap(p[i], p[p[i].second]);
                i--;
            }
        }
        return cnt;
    }
};

int main(){
    

    return 0;
}