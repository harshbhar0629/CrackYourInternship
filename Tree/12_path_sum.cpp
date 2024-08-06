#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/path-sum/description/

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

    bool ans = false;
    void f(TreeNode *root, int target, int sum)
    {
        if (root == NULL || ans)
            return;
        if (!root->left and !root->right and sum + root->val == target)
        {
            ans = true;
        }

        f(root->left, target, sum + root->val);
        f(root->right, target, sum + root->val);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        f(root, targetSum, 0);
        return ans;
    }
};

int main()
{

    return 0;
}