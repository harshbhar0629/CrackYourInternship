#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] == i+1){
                i++;
            }
            else{
                if(nums[nums[i]-1] == nums[i]){
                    i++;
                    continue;
                }
                // cout<<nums[i]<<" "<<nums[nums[i]-1]<<" ";
                swap(nums[i], nums[nums[i]-1]);
                // cout<<nums[i]<<" "<<nums[nums[i]-1]<<" \n";
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return nums[i];
            }
        }

        return n;
    }
};

int main(){
    

    return 0;
}