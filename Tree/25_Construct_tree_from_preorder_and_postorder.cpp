#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

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

    unordered_map<int, int> mp;
    int idx;

    void mapPostorder(vector<int> &post)
    {
        for (int i = 0; i < post.size(); i++)
        {
            mp[post[i]] = i;
        }
    }

    TreeNode *f(vector<int> &pre, vector<int> &post, int st, int end)
    {
        if (st > end || idx >= pre.size())
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[idx++]);
        if (st == end)
        {
            return root;
        }

        int i = mp[pre[idx]];
        root->left = f(pre, post, st, i);
        root->right = f(pre, post, i + 1, end - 1);

        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        idx = 0;
        mapPostorder(post);

        return f(pre, post, 0, pre.size() - 1);
    }
};

int main()
{

    return 0;
}