#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
        {
            return "";
        }
        string data = "";
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            if (curr == NULL)
            {
                data += "#,";
            }
            else
            {
                data += to_string(curr->val) + ",";
            }
            if (curr)
            {
                qu.push(curr->left);
                qu.push(curr->right);
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();

            getline(ss, str, ',');
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                qu.push(curr->left);
            }

            getline(ss, str, ',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                qu.push(curr->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{

    return 0;
}