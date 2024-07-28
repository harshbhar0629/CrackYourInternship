#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0 and arr[i] <= n)
            {
                v[arr[i]] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i + 1] == 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main(){
    

    return 0;
}