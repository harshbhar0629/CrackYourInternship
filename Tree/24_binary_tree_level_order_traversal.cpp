#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            vector<int> v;
            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                v.push_back(curr->val);

                if (curr->left)
                {
                    qu.push(curr->left);
                }
                if (curr->right)
                {
                    qu.push(curr->right);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};

int main()
{

    return 0;
}