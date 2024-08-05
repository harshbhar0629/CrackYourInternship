#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/symmetric-tree/description/

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

    bool isSym(TreeNode *p, TreeNode *q)
    {
        if (p == NULL and q == NULL)
            return true;
        if (p == NULL or q == NULL)
            return false;
        return (p->val == q->val) && isSym(p->left, q->right) && isSym(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *p = root;
        TreeNode *q = root;
        return isSym(p, q);
    }
};

int main()
{

    return 0;
}