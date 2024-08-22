#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximal-rectangle/

class Solution
{

    int histogram(vector<int> &h)
    {
        int n = h.size();
        stack<int> st;
        vector<int> prev(n, -1), next(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and h[st.top()] > h[i])
            {
                next[st.top()] = i;
                st.pop();
            }

            if (!st.empty())
            {
                prev[i] = st.top();
            }
            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int b = next[i] - prev[i] - 1;
            int l = h[i];
            area = max(area, l * b);
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);
        int maxArea = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            int area = histogram(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

int main(){
    

    return 0;
}