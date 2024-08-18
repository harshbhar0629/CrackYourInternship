#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> mp;
        int len = 0;
        int sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (mp.count(sum) == 0)
            {
                mp[sum] = i;
            }
            else
            {
                len = max(len, i - mp[sum]);
            }
        }

        return len;
    }
};

int main(){
    

    return 0;
}