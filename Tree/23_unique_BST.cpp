#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    map<pair<int, int>, vector<TreeNode *>> mp;
    vector<TreeNode *> f(int s, int e)
    {
        if (s > e)
        {
            return {NULL};
        }
        if (mp.find({s, e}) != mp.end())
        {
            return mp[{s, e}];
        }

        vector<TreeNode *> res;
        for (int i = s; i <= e; i++)
        {
            vector<TreeNode *> left = f(s, i - 1);
            vector<TreeNode *> right = f(i + 1, e);

            for (auto left_tree : left)
            {
                for (auto right_tree : right)
                {
                    TreeNode *root = new TreeNode(i, left_tree, right_tree);
                    res.push_back(root);
                }
            }
        }
        return mp[{s, e}] = res;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return f(1, n);
    }
};

int main()
{

    return 0;
}