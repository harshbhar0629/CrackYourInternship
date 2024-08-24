#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/non-overlapping-intervals/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int lastTime = intervals[0][1];
        int overlapping = 0;

        for (int i = 1; i < n; i++)
        {
            if (lastTime > intervals[i][0])
            {
                overlapping++;
                lastTime = min(lastTime, intervals[i][1]);
            }
            else
            {
                lastTime = intervals[i][1];
            }
        }

        return overlapping;
    }
};

int main(){
    

    return 0;
}