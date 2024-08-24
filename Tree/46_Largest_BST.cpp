#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/largest-bst/1

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

struct node
{
    int len, minVal, maxVal;
    node(int l, int mini, int maxi)
    {
        len = l;
        minVal = mini;
        maxVal = maxi;
    }
};

class Solution
{
    int mini = -1e9;
    int maxi = 1e9;
    int ans = 0;
    node f(Node *root)
    {
        if (!root)
        {
            return node({0, maxi, mini});
        }

        auto left = f(root->left);
        auto right = f(root->right);

        if (left.maxVal < root->data and root->data < right.minVal)
        {
            int len = left.len + right.len + 1;
            ans = max(len, ans);
            return node({len, min(left.minVal, root->data), max(root->data, right.maxVal)});
        }

        return node({0, mini, maxi});
    }

public:
    int largestBst(Node *root)
    {
        ans = 0;
        f(root);
        return ans;
    }
};

int main()
{

    return 0;
}