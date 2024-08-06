#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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

    int mini = INT_MAX;
    void f(TreeNode *root, TreeNode *&prev)
    {
        if (root == NULL)
            return;
        f(root->left, prev);
        if (prev)
        {
            // cout<<prev->val<<" ";
            int d = abs(root->val - prev->val);
            mini = min(d, mini);
        }
        prev = root;
        f(root->right, prev);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = NULL;
        f(root, prev);
        return mini;
    }
};

int main()
{

    return 0;
}