#include <bits/stdc++.h>
using namespace std;
//

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

    // int ans=0;

    // int h(TreeNode* root){
    //     if(!root){
    //         return 0;
    //     }

    //     return 1+ max(h(root->left), h(root->right));
    // }

    // void helper(TreeNode* root){
    //     if(!root){
    //         return;
    //     }

    //     int left = h(root->left);
    //     int right = h(root->right);
    //     ans = max(ans, left+right);
    //     helper(root->left);
    //     helper(root->right);
    // }

    int ans = 0;
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = f(root->left);
        int right = f(root->right);
        ans = max(ans, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // helper(root);
        f(root);
        return ans;
    }
};
int main()
{

    return 0;
}