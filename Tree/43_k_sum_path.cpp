#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/k-sum-paths/1


struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    unordered_map<int, int> mp;
    int ans = 0;

    void f(Node *root, int k, int &sum)
    {
        if (!root)
        {
            return;
        }

        sum += root->data;
        ans += mp[sum - k];
        mp[sum]++;

        f(root->left, k, sum);
        f(root->right, k, sum);

        mp[sum]--;
        sum -= root->data;
    }

public:
    int sumK(Node *root, int k)
    {
        mp[0] = 1;
        int sum = 0;
        f(root, k, sum);
        return ans;
    }
};

int main(){
    

    return 0;
}