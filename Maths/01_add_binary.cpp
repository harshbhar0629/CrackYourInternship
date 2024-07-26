#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/add-binary/description/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int cnt = 0;
        string res = "";

        while (i >= 0 and j >= 0)
        {
            cnt += a[i] - '0' + b[j] - '0';
            res += (cnt % 2 == 0) ? '0' : '1';
            cnt /= 2;
            i--, j--;
        }

        while (i >= 0)
        {
            cnt += a[i] - '0';
            res += (cnt % 2 == 0) ? '0' : '1';
            cnt /= 2;
            i--;
        }

        while (j >= 0)
        {
            cnt += b[j] - '0';
            res += (cnt % 2 == 0) ? '0' : '1';
            cnt /= 2;
            j--;
        }

        if (cnt > 0)
        {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    

    return 0;
}