#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

class Solution{
public:
    bool permuteArray(vector<int>& a, vector<int>& b, int k){
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        
        for (int i = 0; i < n; i++){
            if(a[i]+b[i] < k){
                return false;
            }
        }

        return true;
    }
};

int main(){
    

    return 0;
}