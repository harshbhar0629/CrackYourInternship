#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

#define ll long long int
class Solution
{

    bool isPossible(int *a, int n, int k, ll mid)
    {
        int cnt = 1;
        ll val = mid;

        for (int i = 0; i < n; i++)
        {
            if (val >= a[i])
            {
                val -= a[i];
            }
            else
            {
                cnt++;
                val = mid - a[i];
            }
        }

        return cnt <= k;
    }

public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m)
    {
        if (m > n)
        {
            return -1;
        }

        ll lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            lo = max(arr[i] * 1ll, lo);
            hi += arr[i];
        }

        ll ans = 0;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (isPossible(arr, n, m, mid))
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