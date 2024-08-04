#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution
{
public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            // mera current element smaller h jo previous element pde h stack m
            while (!st.empty() and arr[i] < arr[st.top()])
            {
                int idx = st.top();
                st.pop();
                int range = 0;
                if (st.empty())
                {
                    range = i;
                }
                else
                {
                    range = i - st.top() - 1;
                }
                ans[range - 1] = max(ans[range - 1], arr[idx]);
            }
            st.push(i);
        }

        // proceeding for remaining element
        while (!st.empty())
        {
            int idx = st.top();
            st.pop();
            int range = 0;
            if (st.empty())
            {
                range = n;
            }
            else
            {
                range = n - st.top() - 1;
            }
            ans[range - 1] = max(ans[range - 1], arr[idx]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

int main(){
    

    return 0;
}