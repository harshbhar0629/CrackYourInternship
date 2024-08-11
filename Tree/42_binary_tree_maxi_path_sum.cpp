#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    int ans = -1e9;
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = max(0, f(root->left));
        int right = max(0, f(root->right));
        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        f(root);
        return ans;
    }
};

int main()
{

    return 0;
}