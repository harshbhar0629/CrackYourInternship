#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/intersection-of-two-linked-lists/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

    int getLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            head = head->next;
            len++;
        }

        return len;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = getLength(headA);
        int len2 = getLength(headB);

        if (len1 < len2)
        {
            for (int i = 0; i < len2 - len1; i++)
            {
                headB = headB->next;
            }
        }
        else
        {
            for (int i = 0; i < len1 - len2; i++)
            {
                headA = headA->next;
            }
        }

        while (headA and headB)
        {
            if (headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

int main()
{

    return 0;
}