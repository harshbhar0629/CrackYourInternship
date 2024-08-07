#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

struct Node
{
    int data;
    Node *right, *left;
};


class Solution
{
    unordered_set<int> st;
    bool f(Node *root)
    {
        if (!root)
        {
            return false;
        }
        if (!root->left and !root->right)
        {
            if (st.find(root->data + 1) != st.end() and st.find(root->data - 1) != st.end())
            {
                return true;
            }
        }

        st.insert(root->data);
        return f(root->left) || f(root->right);
    }

public:
    bool isDeadEnd(Node *root)
    {
        st.insert(0);
        return f(root);
    }
};

int main()
{

    return 0;
}