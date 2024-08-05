#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-of-bst/description/

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
public:
    void solve(TreeNode *root, int lo, int hi, int &sum)
    {
        if (root == NULL)
            return;
        if (root->val >= lo and root->val <= hi)
            sum += root->val;
        solve(root->left, lo, hi, sum);
        solve(root->right, lo, hi, sum);
    }

    int rangeSumBST(TreeNode *root, int lo, int hi)
    {
        int sum = 0;
        solve(root, lo, hi, sum);
        return sum;
    }
};

int main()
{

    return 0;
}