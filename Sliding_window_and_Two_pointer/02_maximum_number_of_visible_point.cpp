#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-number-of-visible-points/

class Solution
{
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
    {
        vector<double> pointAngles;
        double angles = acos(-1.0);
        int ans = 0;

        for (auto it : points)
        {
            if (it[0] == location[0] and it[1] == location[1])
            {
                ans++;
            }
            else
            {
                int dx = it[0] - location[0];
                int dy = it[1] - location[1];
                double angle = atan2(dy, dx);
                double angle1 = angle * 180 / angles;
                pointAngles.push_back(angle1);
            }
        }

        int n = pointAngles.size();
        sort(pointAngles.begin(), pointAngles.end());
        for (int i = 0; i < n; i++)
        {
            pointAngles.push_back(pointAngles[i] + 360);
        }

        int st = 0, end = 0, cnt = 0;
        while (end < pointAngles.size())
        {
            if (pointAngles[end] - pointAngles[st] > angle)
            {
                st++;
            }
            cnt = max(cnt, end - st + 1);
            end++;
        }

        ans += cnt;
        return ans;
    }
};

int main(){
    

    return 0;
}