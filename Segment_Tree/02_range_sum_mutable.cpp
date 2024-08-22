#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray
{
    int n;
    vector<int> seg;
    void build(int l, int r, int idx, vector<int> &v)
    {
        if (l == r)
        {
            seg[idx] = v[l];
            return;
        }

        int m = (l + r) / 2;
        build(l, m, idx * 2, v);
        build(m + 1, r, idx * 2 + 1, v);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
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

public:
    NumArray(vector<int> &nums)
    {
        this->n = nums.size();
        seg.resize(4 * n, 0);
        build(0, n - 1, 1, nums);
    }

    void update(int idx, int val)
    {
        update(0, n - 1, 1, idx, val);
    }

    int sumRange(int left, int right)
    {
        return q(0, n - 1, 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    

    return 0;
}