#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        Node *curr = root;
        pre = new Node(-1);
        suc = new Node(-1);

        while (curr)
        {
            if (curr->key >= key)
            {
                curr = curr->left;
            }
            else
            {
                pre = curr;
                curr = curr->right;
            }
        }

        curr = root;
        while (curr)
        {
            if (curr->key <= key)
            {
                curr = curr->right;
            }
            else
            {
                suc = curr;
                curr = curr->left;
            }
        }
    }
};

int main(){
    

    return 0;
}