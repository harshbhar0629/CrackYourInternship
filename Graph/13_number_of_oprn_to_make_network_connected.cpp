#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {

    vector<int>rank, par;
    int find(int x){
        if(par[x] == -1){
            return x;
        }
        return par[x] = find(par[x]);
    }

    bool Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return false;
        
        if(rank[a] < rank[b]){
            rank[b]++;
            par[a] = b;
        }
        else{
            rank[a]++;
            par[b] = a;
        }

        return true;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        int cnt=0;
        par.resize(n+1, -1);
        rank.resize(n+1, 1);

        for(auto it: connections){
            int a = it[0];
            int b = it[1];
            if(Union(a, b)){
                cnt++;
            }
        }

        return n - (cnt+1);
    }
};

int main(){
    

    return 0;
}