#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/ugly-number-ii/description/

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        int p2 = 1, p3 = 1, p5 = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            int f1 = dp[p2]*2;
            int f2 = dp[p3]*3;
            int f3 = dp[p5]*5;
            int f = min({f1, f2, f3});

            if(f == f1) p2++;
            if(f == f2) p3++;
            if(f == f3) p5++;
            dp[i] = f;
        }

        return dp[n];
    }
};
int main(){
    

    return 0;
}