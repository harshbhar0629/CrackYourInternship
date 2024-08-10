#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode *> qu;
        qu.push(root);
        int dir = 1;

        while (!qu.empty())
        {
            int size = qu.size();
            vector<int> v(size);

            for (int i = 0; i < size; i++)
            {
                auto curr = qu.front();
                qu.pop();

                int idx = (dir == 1) ? i : size - 1 - i;
                v[idx] = curr->val;

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
            dir *= -1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}