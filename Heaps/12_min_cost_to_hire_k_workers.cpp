#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = wage.size();
        vector<pair<double, int>> ratio;
        for (int i = 0; i < n; i++)
        {
            double rat = (wage[i] * 1.0 / quality[i] * 1.0);
            ratio.push_back({rat, i});
        }

        sort(ratio.begin(), ratio.end());
        double res = 0.0;
        double qualitySum = 0, maxRatio = 0;
        priority_queue<int> pq;

        for (int i = 0; i < k; i++)
        {
            qualitySum += quality[ratio[i].second];
            maxRatio = max(maxRatio, ratio[i].first);
            pq.push(quality[ratio[i].second]);
        }

        res = qualitySum * maxRatio;
        // cout<<res<<" ";
        for (int i = k; i < n; i++)
        {
            qualitySum -= pq.top();
            pq.pop();
            maxRatio = max(maxRatio, ratio[i].first);

            qualitySum += quality[ratio[i].second];
            res = min(qualitySum * maxRatio, res);
            pq.push(quality[ratio[i].second]);
            cout << res << " ";
        }

        return res;
    }
};

int main(){
    

    return 0;
}