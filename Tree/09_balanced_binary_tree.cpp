#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/balanced-binary-tree/description/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution
{
    bool ans;

    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = f(root->left);
        int right = f(root->right);

        if (abs(right - left) > 1)
        {
            ans = false;
        }
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        ans = true;
        f(root);
        return ans;
    }
};

int main()
{

    return 0;
}