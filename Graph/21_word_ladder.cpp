#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-ladder/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st;
        for (auto it : wordList)
        {
            st.insert(it);
        }

        queue<pair<string, int>> qu;
        st.erase(beginWord);
        qu.push({beginWord, 1});

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            string str = curr.first;
            int steps = curr.second;

            for (int i = 0; i < str.size(); i++)
            {
                char orgCh = str[i];
                for (auto ch = 'a'; ch <= 'z'; ch++)
                {
                    str[i] = ch;
                    if (st.find(str) != st.end())
                    {
                        qu.push({str, steps + 1});
                        st.erase(str);
                        if (str == endWord)
                        {
                            return steps + 1;
                        }
                    }
                }
                str[i] = orgCh;
            }
        }

        return 0;
    }
};

int main(){
    

    return 0;
}