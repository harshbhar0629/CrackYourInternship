#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printAllDuplicate(string s)
    {
        vector<int> v(26, 0);
        for (auto ch : s)
        {
            v[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 1)
            {
                cout << ('a' + i) << " " << v[i] << "\n";
            }
        }
    }
};

int main()
{

    return 0;
}