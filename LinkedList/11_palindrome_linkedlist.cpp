#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-linked-list/description/

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

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL, *temp;

        while (curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverse(slow);
        ListNode *start = head;

        while (slow)
        {
            if (start->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            start = start->next;
        }

        return true;
    }
};

int main()
{

    return 0;
}