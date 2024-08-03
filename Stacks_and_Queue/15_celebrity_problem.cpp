#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (mat[a][b] == 1)
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }

        int cnt = 0;
        int cele = st.top();
        for (int i = 0; i < n; i++)
        {
            if (mat[cele][i] == 0)
            {
                cnt++;
            }
        }

        if (cnt != n)
        {
            return -1;
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][cele] == 1 and i != cele)
            {
                cnt++;
            }
        }

        if (cnt != n - 1)
        {
            return -1;
        }

        return cele;
    }
};

int main(){
    

    return 0;
}