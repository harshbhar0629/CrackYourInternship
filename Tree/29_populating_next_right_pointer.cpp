#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                auto temp = curr;
                while (temp)
                {
                    temp->left->next = temp->right;
                    temp->right->next = temp->next ? temp->next->left : NULL;
                    temp = temp->next;
                }
            }
            curr = curr->left;
        }

        return root;
    }
};

int main()
{

    return 0;
}