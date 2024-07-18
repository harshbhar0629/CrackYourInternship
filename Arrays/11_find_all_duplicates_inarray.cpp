#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while(i<n){
            int num = nums[i];
            if(nums[num-1] == num){
                i++;
            }
            else{
                swap(nums[i], nums[num-1]);
            }
        }

        vector<int>res;
        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};

int main(){
    

    return 0;
}