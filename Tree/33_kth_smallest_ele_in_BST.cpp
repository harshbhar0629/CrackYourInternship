#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int ans;
    void f(TreeNode *root, int &k)
    {
        if (!root || ans != -1)
        {
            return;
        }

        f(root->left, k);
        if (--k == 0)
        {
            ans = root->val;
            return;
        }
        f(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        ans = -1;
        f(root, k);
        return ans;
    }
};

int main()
{

    return 0;
}