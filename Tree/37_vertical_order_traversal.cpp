#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

#define f first
#define s second
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> pos;
        queue<pair<TreeNode *, pair<int, int>>> qu;
        qu.push({root, {0, 0}});

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            auto node = curr.f;
            int x = curr.s.f;
            int y = curr.s.s;
            pos[x][y].insert(node->val);

            if (node->left)
            {
                qu.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                qu.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto it : pos)
        {
            vector<int> v;
            for (auto itr : it.s)
            {
                v.insert(v.end(), itr.s.begin(), itr.s.end());
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