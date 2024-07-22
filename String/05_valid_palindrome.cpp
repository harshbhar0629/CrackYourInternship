#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/valid-palindrome-ii/

class Solution
{
    bool f(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++, j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {

        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            if (s[i] != s[j])
            {

                bool ans1 = f(s, i + 1, j);
                bool ans2 = f(s, i, j - 1);
                if (ans1 == false and ans2 == false)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            i++, j--;
        }

        return true;
    }
};

int main(){
    

    return 0;
}