#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/basic-calculator-ii/description/

#define ll long long int
class Solution
{
    int prior_op(char ch)
    {
        if (ch == '/' || ch == '*')
        {
            return 2;
        }
        return 1;
    }

    int solve(int a, int b, char ch)
    {
        if (ch == '*')
        {
            return a * b;
        }
        else if (ch == '/')
        {
            return a / b;
        }
        else if (ch == '+')
        {
            return a + b;
        }
        else
        {
            return a - b;
        }
    }

public:
    int calculate(string s)
    {
        stack<int> number;
        stack<char> oprn;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] >= '0' and s[i] <= '9')
            {
                int num = s[i] - '0';
                // cout<<num<<" ";
                while (i + 1 < n and s[i + 1] >= '0' and s[i + 1] <= '9')
                {
                    // cout<<num<<" ";
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                    // cout<<num<<" 1 ";
                }
                number.push(num);
                // cout<<num<<" 1 ";
            }
            else
            {
                if (oprn.size() == 0 || prior_op(s[i]) > prior_op(oprn.top()))
                {
                    oprn.push(s[i]);
                }
                else
                {
                    while (!oprn.empty() and prior_op(s[i]) <= prior_op(oprn.top()))
                    {
                        int b = number.top();
                        number.pop();
                        int a = number.top();
                        number.pop();
                        char ch = oprn.top();
                        oprn.pop();
                        int ans = solve(a, b, ch);
                        number.push(ans);
                    }
                    // cout<<ans<<" "<<a<<" "<<b<<" "<<" "<<ch<<" \n";
                    oprn.push(s[i]);
                    // cout<<ans<<" 2 ";
                }
            }
        }

        while (!oprn.empty())
        {
            int b = number.top();
            number.pop();
            int a = number.top();
            number.pop();
            char ch = oprn.top();
            oprn.pop();
            int ans = solve(a, b, ch);
            number.push(ans);
            // cout<<ans<<" "<<a<<" "<<b<<" "<<" "<<ch<<" \n";
        }

        return number.top();
    }
};

int main(){
    

    return 0;
}