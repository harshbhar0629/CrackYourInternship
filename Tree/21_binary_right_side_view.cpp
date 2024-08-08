#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }

        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                if (i == 1)
                {
                    ans.push_back(curr->val);
                }

                if (curr->left)
                {
                    qu.push(curr->left);
                }
                if (curr->right)
                {
                    qu.push(curr->right);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}