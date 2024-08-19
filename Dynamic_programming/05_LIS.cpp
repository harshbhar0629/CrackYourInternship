#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Seg
{
    vector<int> seg;
    int n;

    int query(int x, int y, int l, int r, int idx)
    {
        if (r < x || y < l)
        {
            return 0;
        }
        if (x <= l and r <= y)
        {
            return seg[idx];
        }
        int m = (l + r) / 2;
        return max(query(x, y, l, m, idx * 2), query(x, y, m + 1, r, idx * 2 + 1));
    }

    void update(int pos, int val, int l, int r, int idx)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
        {
            update(pos, val, l, m, idx * 2);
        }
        else
        {
            update(pos, val, m + 1, r, idx * 2 + 1);
        }
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

public:
    Seg(int n)
    {
        this->n = n;
        seg.resize(n * 4, 0);
    }

    int query(int x, int y)
    {
        return query(x, y, 0, n - 1, 1);
    }

    void update(int pos, int val)
    {
        return update(pos, val, 0, n - 1, 1);
    }
};

class Solution
{
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        Seg seg(n);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.emplace_back(nums[i], i);
        }

        sort(v.begin(), v.end(), cmp);
        map<pair<int, int>, int> position;

        for (int i = 0; i < n; i++)
        {
            position[v[i]] = i;
        }

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int lb = (lower_bound(v.begin(), v.end(), make_pair(nums[i], -1)) - v.begin());
            int len = seg.query(0, lb);
            len++;
            maxi = max(maxi, len);
            seg.update(position[{nums[i], i}], len);
        }

        return maxi;
    }
};

int main(){
    

    return 0;
}