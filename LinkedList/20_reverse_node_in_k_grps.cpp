#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

    int getLen(ListNode *head)
    {
        int len = 0;
        ListNode *curr = head;
        while (curr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = getLen(head);
        if (!head || len < k)
        {
            return head;
        }

        ListNode *curr = head, *prev = NULL;
        ListNode *after = head;
        int l = 0;

        while (l < k)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
            l++;
        }

        if (after)
            head->next = reverseKGroup(after, k);
        return prev;
    }
};

int main()
{

    return 0;
}