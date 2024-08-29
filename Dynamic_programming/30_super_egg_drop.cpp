#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/super-egg-drop/description/

class Solution
{
    // int dp[102][10002];
    // int f(int eggs, int floor){
    //     if(floor<=1){
    //         return floor;
    //     }
    //     if(eggs==1){
    //         return floor;
    //     }
    //     if(dp[eggs][floor] != -1){
    //         return dp[eggs][floor];
    //     }

    //     int ans = 1e8;
    //     for(int k=1; k<=floor; k++){
    //         int res = 1+ max(f(eggs-1, k-1), f(eggs, floor-k));
    //         ans = min(ans, res);
    //     }

    //     return dp[eggs][floor] = ans;
    // }
public:
    int superEggDrop(int K, int N)
    {
        // memset(dp, -1, sizeof dp);
        // return f(K, N);
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N)
        {
            m++;
            for (int k = 1; k <= K; ++k)
            {
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
            }
        }
        return m;
    }
};

int main(){
    

    return 0;
}