#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/n-queens/

class Solution
{
    vector<vector<string>> ans;
    int left_diagonal[20];  // formula: (n-i+j)
    int right_diagonal[20]; // formula: (i+j)
    int visited[10];

    // bool isPossible(int r, int c, vector<string>& queens){
    //     int i = r, j = c;
    //     // left diagonal
    //     while(i>=0 and j>=0){
    //         if(queens[i][j] == 'Q'){
    //             return false;
    //         }
    //         i--, j--;
    //     }

    //     i = r, j = c;
    //     // right diagonal
    //     while(i>=0 and j<queens.size()){
    //         if(queens[i][j] == 'Q'){
    //             return false;
    //         }
    //         i--, j++;
    //     }

    //     i = r, j = c;
    //     //in same column
    //     while(i>=0){
    //         if(queens[i][j] == 'Q'){
    //             return false;
    //         }
    //         i--;
    //     }

    //     return true;
    // }

    void f(int i, vector<string> &queens, const int &n)
    {
        if (i == n)
        {
            ans.push_back(queens);
            return;
        }

        for (int j = 0; j < n; j++)
        {

            bool left = (left_diagonal[n - i + j] == -1);
            bool right = (right_diagonal[i + j] == -1);
            bool vis = (visited[j] == -1);

            if (left and right and vis)
            {
                left_diagonal[n - i + j] = 1;
                right_diagonal[i + j] = 1;
                visited[j] = 1;
                queens[i][j] = 'Q';

                f(i + 1, queens, n);

                left_diagonal[n - i + j] = -1;
                right_diagonal[i + j] = -1;
                visited[j] = -1;
                queens[i][j] = '.';
            }

            // if(isPossible(i, j, queens)){ // O(1)
            //     queens[i][j] = 'Q';
            //     f(i+1, queens, n);
            //     queens[i][j] = '.';
            // }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> queens(n, string(n, '.'));
        memset(left_diagonal, -1, sizeof left_diagonal);
        memset(right_diagonal, -1, sizeof right_diagonal);
        memset(visited, -1, sizeof visited);
        f(0, queens, n);
        return ans;
    }
};

int main(){
    

    return 0;
}