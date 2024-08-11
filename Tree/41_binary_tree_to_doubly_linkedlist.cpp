#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution
{
    Node *head = NULL;
    Node *prev = NULL;

    void f(Node *root)
    {
        if (!root)
        {
            return;
        }

        f(root->left);
        if (head == NULL)
        {
            prev = head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        f(root->right);
    }

public:
    Node *bToDLL(Node *root)
    {
        f(root);
        return head;
    }
};

int main()
{

    return 0;
}