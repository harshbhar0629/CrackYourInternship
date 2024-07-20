#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += cp[i];
        }

        int maxi = sum;
        int j = k-1;
        for(int i=n-1; i>=n-k; i--){
            sum += cp[i];
            sum -= cp[j];
            j--;
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};

int main(){
    

    return 0;
}