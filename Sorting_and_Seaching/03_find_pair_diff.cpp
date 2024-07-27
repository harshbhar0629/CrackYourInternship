#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int i = 0, j = 1;
        while (i < n and j < n)
        {
            int d = arr[j] - arr[i];
            if (d == x and i != j)
            {
                return 1;
            }
            else if (d < x)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};

int main(){
    

    return 0;
}