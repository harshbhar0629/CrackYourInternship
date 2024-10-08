#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root)
        {
            if (root->val < p->val and root->val < q->val)
            {
                root = root->right;
            }
            else if (root->val > q->val and root->val > p->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}