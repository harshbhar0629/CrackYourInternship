#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
        }

        sort(v.begin(), v.end());
        unordered_set<int> st;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                if (st.find(v[i]) != st.end())
                {
                    int val = v[i] - 1;
                    while (val > 0 and st.find(val) != st.end())
                    {
                        val--;
                    }
                    cnt += v[i] - val;
                    if (val > 0)
                        st.insert(val);
                }
                else
                {
                    st.insert(v[i]);
                }
            }
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}