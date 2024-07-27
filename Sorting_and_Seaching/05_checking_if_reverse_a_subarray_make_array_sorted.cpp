#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool sortArr(vector<int>& a){
        int n = a.size();
        int x = -1, y = -1;
        for (int i = 0; i < n - 1; i++){
            if(a[i] > a[i+1]){
                if(x==-1){
                    x = i;
                }
                y = i + 1;
            }
        }

        if(x != -1){
            // reverse all integer in range of [x..y] and again check now is array sorted if yes then good to go
            reverse(a.begin() + x, a.end() + y + 1);
            for (int i = 0; i < n - 1; i++){
                if (a[i] > a[i + 1]){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    

    return 0;
}