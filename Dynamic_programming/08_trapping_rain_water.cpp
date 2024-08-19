#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        int left_max = 0;
        int maxi[n];

        for (int i = 0; i < n; i++)
        {
            maxi[i] = left_max;
            left_max = max(left_max, height[i]);
        }

        int right_max = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            maxi[i] = right_max;
            right_max = max(right_max, height[i]);
            if (left_max == right_max)
            {
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (height[i] < maxi[i])
            {
                ans += maxi[i] - height[i];
            }
        }

        return ans;

        // for(int i=0; i<n; i++){
        //     int left_max =0 , right_max =0;
        //     for(int j=i; j>=0; j--){
        //         left_max = max(left_max, height[j]);
        //     }
        //     for(int j=i; j<n; j++){
        //         right_max = max(right_max, height[j]);
        //     }

        //     ans += min(left_max, right_max) - height[i];
        // }

        // return ans;
    }
};

int main(){
    

    return 0;
}