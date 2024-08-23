#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == 0)
        {
            return num;
        }

        stack<char> st;
        for (int i = 0; i < num.size(); i++)
        {
            while (!st.empty() and st.top() > num[i] and k > 0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() and k > 0)
        {
            k--;
            st.pop();
        }

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        while (!res.empty() and res.back() == '0')
            res.pop_back();

        reverse(res.begin(), res.end());
        return res == "" ? "0" : res;
    }
};

int main(){
    

    return 0;
}