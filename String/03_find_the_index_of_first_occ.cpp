#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        //    int i = haystack.find(needle);
        //     if(i != string::npos)
        //     {
        //         return i;
        //     }
        //     else
        //     return -1;
        int n = haystack.size();
        int m = needle.size();
        if (m > n)
            return -1;
        for (int i = 0; i < n; i++)
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

int main(){
    

    return 0;
}