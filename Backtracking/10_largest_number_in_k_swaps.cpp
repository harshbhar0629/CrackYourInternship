#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution
{
    string res;
    void f(int i, int cnt, string &str)
    {
        if (i == str.size() || cnt == 0)
        {
            // cout<<str<<" ";
            if (res < str)
            {
                res = str;
            }
            return;
        }
        int k;
        for (k = i + 1; k < str.size(); k++)
        {
            if (str[k] <= str[i])
            {
                continue;
            }
            // cout<<" aya ";
            swap(str[i], str[k]);
            f(i + 1, cnt - 1, str);
            swap(str[i], str[k]);
        }

        // to handle the edge case for "321"
        if (k == str.size() && i < k)
        {
            f(i + 1, cnt, str);
        }
    }

public:
    string findMaximumNum(string str, int k)
    {
        res = str;
        f(0, k, str);
        // cout<<"\n";
        return res;
    }
};

int main(){
    

    return 0;
}