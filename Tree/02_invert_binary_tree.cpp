#include <bits/stdc++.h>
using namespace std;

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

    void f(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        f(root->left);
        f(root->right);
    }

public:
    TreeNode *invertTree(TreeNode *root)
    {
        f(root);
        return root;
    }
};

int main()
{

    return 0;
}