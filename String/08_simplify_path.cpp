#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/simplify-path/description/

class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.size();
        stack<string> st;

        for (int i = 0; i < n; i++)
        {
            if (path[i] == '/')
            {
                continue;
            }
            string temp = "";
            while (i < path.size() and path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            if (temp == ".")
            {
                continue;
            }
            else if (temp == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }

        string res = "";
        while (!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        if (res == "")
        {
            return "/";
        }
        return res;
    }
};

int main(){
    

    return 0;
}