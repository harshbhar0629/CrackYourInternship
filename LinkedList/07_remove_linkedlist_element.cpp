#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-linked-list-elements/

// Definition for singly-linked list.
  struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // if starting value is point to same given value
        ListNode *temp = head;
        while (temp != NULL and temp->val == val)
        {
            temp = temp->next;
        }
        head = temp;

        while (temp != NULL and temp->next != NULL)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}