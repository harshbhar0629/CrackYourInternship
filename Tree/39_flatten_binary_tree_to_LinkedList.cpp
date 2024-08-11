#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                auto left = curr->left;
                while (left->right)
                {
                    left = left->right;
                }
                left->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
};

int main()
{

    return 0;
}