#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

struct Node *f(int &i, int pre[], char preLN[], int n)
{
    if (i >= n)
    {
        return NULL;
    }

    Node *root = new Node(pre[i]);
    if (preLN[i] == 'L')
    {
        return root; // it means it is a leaf node
    }

    i += 1;
    root->left = f(i, pre, preLN, n);
    i += 1;
    root->right = f(i, pre, preLN, n);

    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = 0;
    auto root = f(i, pre, preLN, n);
    return root;
}

int main()
{

    return 0;
}