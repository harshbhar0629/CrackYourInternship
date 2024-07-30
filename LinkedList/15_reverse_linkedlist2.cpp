#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
        ListNode *prev = NULL;

        while (curr)
        {
            auto after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }

        return prev;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *beforeStart = NULL, *start = NULL, *end = NULL, *afterEnd = NULL;
        int len = 1;
        ListNode *temp = head;

        while (temp)
        {
            if (len + 1 == left)
            {
                beforeStart = temp;
            }
            else if (len == left)
            {
                start = temp;
            }
            else if (len == right)
            {
                end = temp;
            }
            else if (len == 1 + right)
            {
                afterEnd = temp;
            }
            len += 1;
            temp = temp->next;
        }

        end->next = NULL;
        end = reverse(start);
        if (beforeStart)
        {
            beforeStart->next = end;
        }

        start->next = afterEnd;
        if (beforeStart)
        {
            return head;
        }

        return end;
    }
};

int main()
{

    return 0;
}