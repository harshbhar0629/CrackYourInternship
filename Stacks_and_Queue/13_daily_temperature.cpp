#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/daily-temperatures/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and temp[st.top()] < temp[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}