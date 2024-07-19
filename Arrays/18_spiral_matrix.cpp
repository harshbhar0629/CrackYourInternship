#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> v;

        int maxr = n - 1;
        int minr = 0;
        int maxc = m - 1;
        int minc = 0;
        int tne = n * m;
        int count = 0;
        while (count < tne)
        {
            for (int j = minc; j <= maxc && count < tne; j++)
            {
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;

            for (int i = minr; i <= maxr && count < tne; i++)
            {
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;

            for (int j = maxc; j >= minc && count < tne; j--)
            {
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;

            for (int i = maxr; i >= minr && count < tne; i--)
            {
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return v;
    }
};

int main(){
    

    return 0;
}