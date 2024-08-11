#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution
{
    int i = 0;
    Node *f(int pre[], int n, int mini, int maxi)
    {
        if (i >= n || pre[i] < mini || maxi < pre[i])
        {
            return NULL;
        }

        Node *root = newNode(pre[i++]);
        root->left = f(pre, n, mini, root->data);
        root->right = f(pre, n, root->data, maxi);

        return root;
    }

public:
    Node *Bst(int pre[], int size)
    {
        i = 0;
        return f(pre, size, -1e9, 1e9);
    }
};

int main()
{

    return 0;
}