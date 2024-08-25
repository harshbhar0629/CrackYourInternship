#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/phone-directory4628/1

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        const int m = s.size();
        vector<vector<string>> ans(m, vector<string>());
        sort(contact, contact + n);

        for (int i = 0; i < n; ++i)
        {
            string word = contact[i];
            if (i > 0 and word == contact[i - 1])
                continue;

            int j = 0;
            while (j < m and j < word.size() and s[j] == word[j])
                ans[j++].push_back(word);
        }

        for (int j = 0; j < m; ++j)
        {
            if (ans[j].empty())
                ans[j].push_back("0");
        }

        return ans;
    }
};

int main(){
    

    return 0;
}