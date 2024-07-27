#include <bits/stdc++.h>
using namespace std;

class Solution{
    int computeCost(vector<int>& a, int x){
        int cost = 0;
        for(auto it: a){
            cost += abs(it - x);
        }

        return cost;
    }

public:
    int minCost(vector<int> &a){
        int n = a.size();
        int lo = a[0], hi = a[0];
        for (int i = 1; i < n; i++){
            lo = min(lo, a[i]);
            hi = max(hi, a[i]);
        }

        while (hi - lo > 2){
            int m1 = lo + (hi - lo) / 3;
            int m1 = hi - (hi - lo) / 3;
            int c1 = computeCost(a, m1);
            int c2 = computeCost(a, m2);

            if(c1<c2){
                hi = m2;
            }
            else{
                lo = m1;
            }
        }

        return computeCost(a, (lo + hi) / 2);
    }
};

int main()
{

    return 0;
}