#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flood-fill/

class Solution {
    int n, m, color;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    // simple-dfs
    void f(vector<vector<int>>& g, int row, int col, int newColor){
        if(row<0 || col<0 || col>=m || row>=n || g[row][col] != color || g[row][col] == newColor){
            return;
        }
        g[row][col] = newColor;
        for(int i=0; i<4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            f(g, nr, nc, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        this->n = img.size();
        this->m = img[0].size();
        this->color = img[sr][sc];
        f(img, sr, sc, color);
        
        return img;
    }
};

int main(){
    

    return 0;
}
