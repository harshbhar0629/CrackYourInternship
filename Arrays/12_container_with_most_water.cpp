#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int i = 0, j = n-1;
        int maxArea = 0;

        while(i<j){
            int area = (min(h[i], h[j]))*(j-i);
            if(h[i] <= h[j]){
                i++;
            }
            else{
                j--;
            }
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

int main(){
    

    return 0;
}