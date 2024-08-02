#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

class Solution
{
    int solve(int a, int b, char ch)
    {
        if (ch == '+')
        {
            return a + b;
        }
        if (ch == '-')
        {
            return a - b;
        }
        if (ch == '*')
        {
            return a * b;
        }
        return a / b;
    }

public:
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for (auto it : S)
        {
            // cout<<it<<" ";
            if (it >= '0' and it <= '9')
            {
                st.push(it - '0');
            }
            else
            {

                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                // cout<<x<<" "<<y<<" "<<it<<"\n";
                st.push(solve(x, y, it));
            }
        }
        // cout<<endl;
        return st.top();
    }
};

int main(){
    

    return 0;
}