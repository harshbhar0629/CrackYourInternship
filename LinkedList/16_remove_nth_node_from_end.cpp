#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;

        for (int i = 1; i <= n + 1; i++)
        {
            if (!fast)
                return head->next;
            fast = fast->next;
        }

        ListNode *slow = head;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main()
{

    return 0;
}