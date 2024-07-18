#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/4sum/description/

#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, ll target) {
        set<vector<int>>unique;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n; j++){
                int k = j+1, l = n-1;
                while(k<l){
                    ll sum = nums[i]*1ll + nums[j]*1ll + nums[k]*1ll + nums[l]*1ll;
                    if(sum == target){
                        unique.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }

        vector<vector<int>>res;
        for(auto it: unique){
            res.emplace_back(it);
        }

        return res;
    }
};

int main(){
    

    return 0;
}