#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sum-of-subarray-minimums/description/

#define ll long long int
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<ll> left(n), right(n);
        stack<pair<int, int>> prev_st, next_st;

        for (int i = 0; i < n; i++)
        {
            left[i] = i + 1;
            right[i] = n - i;
            // cout<<left[i]<<" "<<right[i]<<" \n";
        }

        for (int i = 0; i < n; i++)
        {
            while (!prev_st.empty() and prev_st.top().first > arr[i])
            {
                prev_st.pop();
            }
            left[i] = prev_st.empty() ? i + 1 : i - prev_st.top().second;
            prev_st.push({arr[i], i});

            while (!next_st.empty() and next_st.top().first > arr[i])
            {
                auto curr = next_st.top();
                next_st.pop();
                right[curr.second] = i - curr.second;
            }
            next_st.push({arr[i], i});
        }

        ll ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            ans += (arr[i] * left[i] * right[i]) % mod;
            ans %= mod;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}