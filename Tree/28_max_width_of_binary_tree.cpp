#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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

#define ll long long int
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        ll maxWidth = 0;
        queue<pair<TreeNode *, ll>> qu;
        qu.push({root, 1});

        while (!qu.empty())
        {
            ll stWidth = qu.front().second;
            ll endWidth = 0;

            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                ll width = curr.second - stWidth;

                if (i == 1)
                {
                    endWidth = curr.second;
                }
                if (curr.first->left)
                {
                    qu.push({curr.first->left, 2 * width + 1});
                }
                if (curr.first->right)
                {
                    qu.push({curr.first->right, 2 * width + 2});
                }
            }

            maxWidth = max(maxWidth, endWidth - stWidth + 1);
        }

        return maxWidth;
    }
};

int main()
{

    return 0;
}