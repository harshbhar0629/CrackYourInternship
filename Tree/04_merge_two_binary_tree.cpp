#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

    TreeNode *f(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)
        {
            return NULL;
        }
        if (!root1 and root2)
        {
            return root2;
        }
        if (root1 and !root2)
        {
            return root1;
        }

        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = f(root1->left, root2->left);
        root->right = f(root1->right, root2->right);
        return root;
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return f(root1, root2);
    }
};

int main()
{

    return 0;
}