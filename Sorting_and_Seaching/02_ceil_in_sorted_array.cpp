#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

class Solution{
public:
    int ceilSearch(vector<int>& a, int k){
        int n = a.size();
        int lo = 0, hi = n - 1;
        int ans = 0;
        while(lo<=hi){
            int m = (lo + hi) / 2;
            if(a[m] <= k){
                lo = m + 1;
                ans = m;
            }
            else{
                hi = m - 1;
            }
        }
        
        return ans;
    }
};

int main(){
    

    return 0;
}