#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-paths/description/

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
    vector<string> res;
    void f(string s, TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        string a = to_string(root->val);
        if (!root->left and !root->right)
        {
            s += a;
            res.push_back(s);
            return;
        }

        f(s + a + "->", root->left);
        f(s + a + "->", root->right);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        f("", root);
        return res;
    }
};

int main()
{

    return 0;
}