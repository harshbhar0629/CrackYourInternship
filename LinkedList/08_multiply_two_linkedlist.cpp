#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

// Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

#define ll long long int
class solution
{
public:
    ll multiplyTwoLists(Node *first, Node *second)
    {
        const ll mod = 1e9 + 7;
        ll val1 = 0;
        while (first)
        {
            val1 = val1 * 10 + first->data;
            val1 %= mod;
            first = first->next;
        }

        ll val2 = 0;
        while (second)
        {
            val2 = val2 * 10 + second->data;
            val2 %= mod;
            second = second->next;
        }

        return (val1 * val2) % mod;
    }
};

int main(){
    

    return 0;
}