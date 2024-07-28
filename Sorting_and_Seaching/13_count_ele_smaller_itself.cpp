#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

class Seg
{
    vector<int> seg;

public:
    Seg(int n)
    {
        seg.resize(n * 4, 0);
    }

    void update(int l, int r, int idx, int pos, int val)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m)
        {
            update(l, m, idx * 2, pos, val);
        }
        else
        {
            update(m + 1, r, idx * 2 + 1, pos, val);
        }

        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    int q(int l, int r, int idx, int x, int y)
    {
        if (y < l || r < x)
        {
            return 0;
        }
        if (x <= l and r <= y)
        {
            return seg[idx];
        }

        int m = (l + r) / 2;
        int left = q(l, m, idx * 2, x, y);
        int right = q(m + 1, r, idx * 2 + 1, x, y);

        return left + right;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> val_and_idx;
        int n = nums.size();
        Seg seg(n);

        for (int i = 0; i < n; i++)
        {
            val_and_idx.emplace_back(nums[i], i);
        }

        sort(val_and_idx.begin(), val_and_idx.end());
        map<pair<int, int>, int> position;

        for (int i = 0; i < n; i++)
        {
            position[val_and_idx[i]] = i;
        }

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int idx = position[{nums[i], i}];

            int val = seg.q(0, n - 1, 1, 0, idx);
            seg.update(0, n - 1, 1, idx, 1);

            ans[i] = val;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}