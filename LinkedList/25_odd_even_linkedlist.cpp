#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL)
            return NULL;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (even and even->next)
        {
            odd->next = odd->next->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

int main()
{

    return 0;
}