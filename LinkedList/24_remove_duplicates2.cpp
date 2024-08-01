#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next and head->next->next)
        {
            if (head->next->val == head->next->next->val)
            {
                ListNode *temp = head->next;
                while (temp and temp->val == head->next->val)
                {
                    temp = temp->next;
                }

                head->next = temp;
            }
            else
            {
                head = head->next;
            }
        }

        return dummy->next;
    }
};

int main()
{

    return 0;
}