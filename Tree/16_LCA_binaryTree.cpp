#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

    TreeNode *f(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || !root)
        {
            return root;
        }
        auto left = f(root->left, p, q);
        auto right = f(root->right, p, q);

        if (left and right)
        {
            return root;
        }
        else if (!left and right)
        {
            return right;
        }
        else if (left and !right)
        {
            return left;
        }
        else
        {
            return NULL;
        }
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return f(root, p, q);
    }
};

int main()
{

    return 0;
}