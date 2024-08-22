#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution
{
    vector<vector<int>> dp;
    int f(int i, int sum, int *arr, int n)
    {
        if (sum == 0)
        {
            return 1;
        }
        if (i == n)
        {
            return 0;
        }
        if (dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        return dp[i][sum] = f(i + 1, sum, arr, n) || (arr[i] <= sum ? f(i + 1, sum - arr[i], arr, n) : 0);
    }

public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if (sum % 2)
        {
            return 0;
        }

        sum /= 2;
        dp.resize(n + 1, vector<int>(sum + 1, -1));
        return f(0, sum, arr, n);
    }
};

int main(){
    

    return 0;
}