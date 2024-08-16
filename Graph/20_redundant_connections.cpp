#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/redundant-connection/

class Solution {

    vector<int>par, rank;
    int find(int x){
        if(par[x] == -1){
            return x;
        }
        return par[x] = find(par[x]);
    }

    bool Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a==b){
            return true;
        }

        if(rank[a] < rank[b]){
            rank[b]++;
            par[a] = b;
        }
        else{
            rank[a]++;
            par[b] = a;
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        rank.resize(edges.size()+1, 1);
        par.resize(edges.size()+1, -1);
        for(auto it: edges){
            int a = it[0];
            int b = it[1];
            
            bool res = Union(a, b);
            if(res){
                ans = it;
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}