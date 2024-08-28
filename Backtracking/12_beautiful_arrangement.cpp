#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/beautiful-arrangement/

class Solution
{
    int dp[16][1 << 16];

    int f(int idx, int n, int currBits)
    {
        if (idx == n)
        {
            return 1;
        }
        if (dp[idx][currBits] != -1)
        {
            return dp[idx][currBits];
        }

        int ans = 0;
        int currVal = idx + 1;
        for (int i = 0; i < n; i++)
        {
            if ((currBits >> i) & 1)
                continue;
            if ((i + 1) % currVal == 0 || currVal % (i + 1) == 0)
            {
                ans += f(idx + 1, n, currBits | (1 << i));
            }
        }

        return dp[idx][currBits] = ans;
    }

    // int ans = 0;
    // void f(int val, int n, vector<int>& v){
    //     if(val>n){
    //         ans++;
    //         return;
    //     }

    //     for(int i=1; i<=n; i++){
    //         if(v[i] == 0 and (i%val == 0 || val%i == 0)){
    //             v[i] = 1; // mark as visited
    //             f(val+1, n, v);
    //             v[i] = 0; // mark as unvisited after call
    //         }
    //     }
    // }

public:
    int countArrangement(int n)
    {
        // vector<int>v(n+1, 0);
        // f(1, n, v);
        // return ans;
        memset(dp, -1, sizeof dp);
        return f(0, n, 0);
    }
};

int main(){
    

    return 0;
}