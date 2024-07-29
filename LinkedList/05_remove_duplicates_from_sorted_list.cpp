#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
        ListNode *temp = head;
        while (temp and temp->next)
        {
            if (temp->val == temp->next->val)
            {
                int val = temp->val;
                auto t = temp;
                while (t and t->val == val)
                {
                    t = t->next;
                }
                temp->next = t;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{

    return 0;
}