#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;

        for (auto it : s)
        {
            if (st.empty() || st.top().first != it)
            {
                st.push({it, 1});
            }
            else
            {
                auto prev = st.top();
                st.pop();
                st.push({it, prev.second + 1});
            }
            if (st.top().second == k)
            {
                st.pop();
            }
        }

        string res = "";
        while (!st.empty())
        {
            auto curr = st.top();
            while (curr.second)
            {
                res += curr.first;
                curr.second--;
            }
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    

    return 0;
}