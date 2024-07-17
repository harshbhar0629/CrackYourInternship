#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

class Solution
{
public:
    long long findMinDiff(vector<long long> a, int n, int m)
    {
        long long ans = 1e12;
        sort(a.begin(), a.end());

        for (int i = 0; i < n - m + 1; i++)
        {
            ans = min(ans, a[i + m - 1] - a[i]);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}