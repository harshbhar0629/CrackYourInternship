#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

#define ll long long int

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<ll> productExceptSelf(vector<ll> &nums, int n)
    {
        vector<ll> p(n);
        ll pdt = 1;
        for (int i = 0; i < n; i++)
        {
            p[i] = pdt;
            pdt *= nums[i];
        }

        pdt = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            p[i] = pdt * p[i];
            pdt *= nums[i];
        }

        return p;
    }
};

int main(){
    

    return 0;
}