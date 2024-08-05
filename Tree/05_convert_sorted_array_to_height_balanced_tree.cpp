#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

    TreeNode *f(vector<int> &nums, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        int m = (s + e) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = f(nums, s, m - 1);
        root->right = f(nums, m + 1, e);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = f(nums, 0, nums.size() - 1);
        return root;
    }
};

int main()
{

    return 0;
}