#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

class Node
{
public:
    Node *left, *right;
    int data;
    Node(int data = 0, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
    int cnt;

    void f(Node *root, int l, int h)
    {
        if (!root)
        {
            return;
        }

        if (root->data >= l and root->data <= h)
        {
            cnt++;
        }

        f(root->left, l, h);
        f(root->right, l, h);
    }

public:
    int getCount(Node *root, int l, int h)
    {
        cnt = 0;
        f(root, l, h);
        return cnt;
    }
};

int main()
{

    return 0;
}