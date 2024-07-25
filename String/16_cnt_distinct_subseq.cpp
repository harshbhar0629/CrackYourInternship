#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/distinct-subsequences/description/

class Solution {
    int dp[1005][1005];
    int f(int i, int j, const string& s, const string& t){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int skip = f(i+1, j, s, t);
        int inc = 0;
        if(s[i] == t[j]){
            inc = f(i+1, j+1, s, t);
        }

        return dp[i][j] = skip+inc;
    }

public:
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, s, t);    
    }
};

int main(){
    

    return 0;
}