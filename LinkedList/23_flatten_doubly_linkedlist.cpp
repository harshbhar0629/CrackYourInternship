#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            Node *nextPointer = curr->next;
            if (curr->child)
            {
                // if child exist
                Node *child = curr->child;
                curr->child = NULL;
                child = flatten(child);
                curr->next = child;
                child->prev = curr;

                while (child->next)
                {
                    child = child->next;
                }
                child->next = nextPointer;
                if (nextPointer)
                {
                    nextPointer->prev = child;
                }
            }
            curr = nextPointer;
        }

        return head;
    }
};

int main(){
    

    return 0;
}