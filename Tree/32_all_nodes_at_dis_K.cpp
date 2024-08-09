#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    using T = TreeNode;
    unordered_map<T *, T *> childToParent;

    void setParent(T *root)
    {
        queue<T *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            if (curr->left)
            {
                childToParent[curr->left] = curr;
                qu.push(curr->left);
            }

            if (curr->right)
            {
                qu.push(curr->right);
                childToParent[curr->right] = curr;
            }
        }
    }

public:
    vector<int> distanceK(T *root, T *target, int k)
    {
        setParent(root);

        int level = 0;
        queue<T *> qu;
        unordered_map<T *, int> vis;
        vis[target]++;
        qu.push(target);

        while (!qu.empty())
        {
            if (level++ == k)
            {
                break;
            }

            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                if (curr->left and !vis[curr->left])
                {
                    vis[curr->left]++;
                    qu.push(curr->left);
                }
                if (curr->right and !vis[curr->right])
                {
                    qu.push(curr->right);
                    vis[curr->right]++;
                }
                if (childToParent.count(curr) > 0 and !vis[childToParent[curr]])
                {
                    qu.push(childToParent[curr]);
                    vis[childToParent[curr]]++;
                }
            }
        }

        vector<int> ans;
        while (!qu.empty())
        {
            ans.push_back(qu.front()->val);
            qu.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}