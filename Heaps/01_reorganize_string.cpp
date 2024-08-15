#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorganize-string/description/

#define pp pair<int, char>
class Solution
{
public:
    string reorganizeString(string s)
    {
        vector<int> v(26, 0);
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            v[s[i] - 'a']++;
            cnt = max(cnt, v[s[i] - 'a']);
        }
        if (cnt > (n + 1) / 2)
        {
            return "";
        }

        priority_queue<pp> pq;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                pq.push({v[i], i + 'a'});
            }
        }

        string ans = "";
        while (pq.size() > 1)
        {
            auto it = pq.top();
            pq.pop();
            auto itr = pq.top();
            pq.pop();
            ans += it.second;
            ans += itr.second;
            it.first--;
            itr.first--;
            if (it.first > 0)
            {
                pq.push(it);
            }
            if (itr.first > 0)
            {
                pq.push(itr);
            }
        }

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ans += it.second;
        }

        return ans;
    }
};

int main()
{

    return 0;
}