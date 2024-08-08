#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/validate-binary-search-tree/description/

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

#define ll long long int
class Solution
{

    bool f(TreeNode *root, ll mini, ll maxi)
    {
        if (!root)
        {
            return true;
        }

        if (root->val <= mini || maxi <= root->val)
        {
            return false;
        }

        auto left = f(root->left, mini, root->val);
        auto right = f(root->right, root->val, maxi);

        return left and right;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        ll mini = -1e14;
        ll maxi = 1e14;

        return f(root, mini, maxi);
    }
};

int main()
{

    return 0;
}