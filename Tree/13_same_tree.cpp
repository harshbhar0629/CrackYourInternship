#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/same-tree/description/

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

    bool f(TreeNode *p, TreeNode *q)
    {
        if (!p and !q)
        {
            return true;
        }
        if (!p || !q || p->val != q->val)
        {
            return false;
        }

        bool left = f(p->left, q->left);
        bool right = f(p->right, q->right);

        return left and right;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return f(p, q);
    }
};

int main()
{

    return 0;
}