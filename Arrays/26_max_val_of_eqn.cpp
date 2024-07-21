#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/max-value-of-equation/description/

class Solution
{
    // Observation: Here the equation is yi + yj + |xi - xj| and xj > xi .
    // So, |xi - xj| will be always negative. We can write the
    // equation as yi + yj - xi + xj
    // yi - xi and store it in a priority queue along with xi
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        int ans = -1e9;

        for (int i = 0; i < n; i++)
        {
            while (!pq.empty() and points[i][0] - pq.top().second > k)
            {
                pq.pop();
            }

            if (!pq.empty())
            {
                ans = max(ans, pq.top().first + points[i][0] + points[i][1]);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }

        return ans;
    }
};

int main(){
    

    return 0;
}