#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-list/description/

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

    ListNode *merge(ListNode *A, ListNode *B)
    {
        ListNode *C = new ListNode(-1);
        ListNode *temp = C;

        while (A and B)
        {
            if (A->val < B->val)
            {
                temp->next = A;
                A = A->next;
            }
            else
            {
                temp->next = B;
                B = B->next;
            }
            temp = temp->next;
        }

        if (A)
        {
            temp->next = A;
        }
        else
        {
            temp->next = B;
        }

        return C->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *fast = head, *slow = head;
        while (fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *a = slow->next;
        slow->next = NULL;
        ListNode *b = head;

        a = sortList(a);
        b = sortList(b);

        return merge(a, b);
    }
};

int main()
{

    return 0;
}