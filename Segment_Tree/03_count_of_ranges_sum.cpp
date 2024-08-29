#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-of-range-sum/description/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
class Solution {
    tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        oset.insert(0);
        ll sum = 0, ans = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            ans += oset.order_of_key(sum - lower + 1) - oset.order_of_key(sum - upper);
            // cout<<oset.order_of_key(sum - lower + 1)<<" "<<oset.order_of_key(sum - upper)<<"\n";
            oset.insert(sum);
            // cout<<ans<<" "<<sum-lower+1<<" "<<sum-upper<<"\n";
        }

        return ans;
    }
};
// 0 -2 3 -2

int main(){
    

    return 0;
}