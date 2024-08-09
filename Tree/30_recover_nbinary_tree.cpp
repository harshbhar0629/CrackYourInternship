#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/recover-binary-search-tree/

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
    using T = TreeNode;

    void f(T *root, T *&first, T *&second, T *&prev)
    {
        if (!root)
        {
            return;
        }

        f(root->left, first, second, prev);
        if (prev and prev->val > root->val)
        {
            if (!first)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        f(root->right, first, second, prev);
    }

public:
    void recoverTree(TreeNode *root)
    {
        T *first = NULL;
        T *second = NULL;
        T *prev = NULL;

        f(root, first, second, prev);
        swap(first->val, second->val);
    }
};

int main()
{

    return 0;
}