#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

    vector<int> in;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *node)
    {
        // inorder(node);
        // return in;
        in.clear();
        if (node == NULL)
            return in;
        TreeNode *root = node;
        stack<TreeNode *> st;
        while (true)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.size() == 0)
                    break;
                root = st.top();
                in.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return in;
    }
};

int main()
{

    return 0;
}