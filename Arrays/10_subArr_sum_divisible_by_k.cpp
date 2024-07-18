#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = ((sum%k)<0)? (sum%k)+k: sum%k;
            ans += mp[rem];
            mp[rem]++;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}