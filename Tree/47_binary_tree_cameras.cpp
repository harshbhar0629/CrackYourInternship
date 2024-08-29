#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-cameras/description/

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
    int cntCamera;
    // 2 means place camera here
    // 1 means our adjacent neighbour having camera
    // 0 means our adjacent neighbour don't have camera
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 1;
        }

        int left = f(root->left);
        int right = f(root->right);

        if (left == 0 || right == 0)
        {
            cntCamera++;
            return 2;
        }
        if (left == 1 and right == 1)
        {
            return 0;
        }

        return 1;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        cntCamera = 0;
        int val = f(root);
        if (val == 0)
            cntCamera++;
        return cntCamera;
    }
};

int main()
{

    return 0;
}