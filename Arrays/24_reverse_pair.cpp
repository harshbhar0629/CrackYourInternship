#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-pairs/description/

#define ll long long int
class Solution
{
    int ans = 0;
    void merge(int lo, int mid, int hi, vector<int> &nums)
    {
        int i = lo, j = mid + 1;
        while (i <= mid and j <= hi)
        {
            if (nums[i] * 1ll > 1ll * 2 * nums[j])
            {
                ans += mid - i + 1;
                j++;
            }
            else
            {
                i++;
            }
        }

        i = lo, j = mid + 1;
        vector<int> v;
        while (i <= mid and j <= hi)
        {
            if (nums[i] <= nums[j])
            {
                v.emplace_back(nums[i++]);
            }
            else
            {
                v.emplace_back(nums[j++]);
            }
        }

        while (i <= mid)
        {
            v.emplace_back(nums[i++]);
        }
        while (j <= hi)
        {
            v.emplace_back(nums[j++]);
        }

        for (int k = 0; k < v.size(); k++)
        {
            nums[k + lo] = v[k];
        }
    }

    void mergeSort(int lo, int hi, vector<int> &nums)
    {
        if (lo == hi)
            return;
        int m = (lo + hi) / 2;
        mergeSort(lo, m, nums);
        mergeSort(m + 1, hi, nums);
        merge(lo, m, hi, nums);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        mergeSort(0, nums.size() - 1, nums);
        return ans;
    }
};

int main(){
    

    return 0;
}