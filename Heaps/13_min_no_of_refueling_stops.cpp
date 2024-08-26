#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int cnt = 0, max_reach = startFuel;
        int n = stations.size(), i = 0;
        priority_queue<int> pq;

        while (max_reach < target)
        {
            while (i < n and stations[i][0] <= max_reach)
            {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty())
            {
                return -1;
            }
            max_reach += pq.top();
            pq.pop();
            cnt++;
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}