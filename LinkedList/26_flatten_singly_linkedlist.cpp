#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution
{
    Node *merge(Node *a, Node *b)
    {
        Node *head = new Node(0);
        Node *temp = head;
        while (a and b)
        {
            if (a->data < b->data)
            {
                temp->bottom = a;
                a = a->bottom;
            }
            else
            {
                temp->bottom = b;
                b = b->bottom;
            }
            temp = temp->bottom;
        }
        if (a)
        {
            temp->bottom = a;
        }
        else
        {
            temp->bottom = b;
        }

        return head->bottom;
    }

public:
    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == NULL)
        {
            return root;
        }

        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};
int main()
{

    return 0;
}