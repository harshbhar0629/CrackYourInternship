#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{

    int cnt_smaller_ele(vector<vector<int>> &mat, int mid)
    {
        int n = mat.size();
        int j = n - 1, i = 0;
        int cnt = 0;

        while (i < n and j >= 0)
        {
            if (mat[i][j] <= mid)
            {
                cnt += j + 1;
                i++;
            }
            else
            {
                j--;
            }
        }

        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int lo = mat[0][0];
        int hi = mat[n - 1][n - 1];

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            // int cnt = 0;
            // for(int i=0; i<n; i++){
            //     cnt+= upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            // }
            int cnt = cnt_smaller_ele(mat, mid);
            if (cnt < k)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};

int main(){
    

    return 0;
}