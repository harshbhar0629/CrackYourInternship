#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/median-of-bst/1

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

vector<int> in;
void f(Node *root)
{
    if (!root)
    {
        return;
    }

    f(root->left);
    in.push_back(root->data);
    f(root->right);
}

float findMedian(struct Node *root)
{
    in = {};
    f(root);

    int n = in.size();
    if (n % 2 == 0)
    {
        return (float)(in[n / 2] + in[n / 2 - 1]) / 2.0;
    }
    return in[n / 2];
}

int main()
{

    return 0;
}