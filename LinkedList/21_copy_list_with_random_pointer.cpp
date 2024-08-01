#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/copy-list-with-random-pointer/description/


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // create deep copy
        Node *deepCopy = new Node(0);
        Node *tempH = head;
        Node *tempC = deepCopy;

        while (tempH)
        {
            tempC->next = new Node(tempH->val);
            tempC = tempC->next;
            tempH = tempH->next;
        }
        // new Original deep copy
        deepCopy = deepCopy->next;
        // merge all original node with deep copy
        tempH = head;
        tempC = deepCopy;

        Node *dummy = new Node(0);
        Node *tempD = dummy;
        while (tempH)
        {
            tempD->next = tempH;
            tempD = tempD->next;
            tempH = tempH->next;

            tempD->next = tempC;
            tempC = tempC->next;
            tempD = tempD->next;
        }

        // now set random pointer
        dummy = dummy->next;
        tempH = dummy;
        while (tempH and tempH->next)
        {
            if (tempH->random)
            {
                tempH->next->random = tempH->random->next;
            }
            tempH = tempH->next->next;
        }

        // now separate all nodes
        tempD = dummy;
        Node *newHead = new Node(0);
        tempH = newHead;
        Node *res = new Node(0);
        tempC = res;
        while (tempD)
        {
            tempC->next = tempD;
            tempC = tempC->next;
            tempD = tempD->next;

            tempH->next = tempD;
            tempH = tempH->next;
            tempD = tempD->next;
        }

        tempH->next = tempC->next = NULL;
        return newHead->next;
    }
};

int main(){
    

    return 0;
}