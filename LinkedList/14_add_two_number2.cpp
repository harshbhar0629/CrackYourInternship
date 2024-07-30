#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/add-two-numbers-ii/description/

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (head)
        {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;

        while (l1 or l2)
        {
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(carry % 10);
            temp = temp->next;
            carry /= 10;
        }

        if (carry)
        {
            temp->next = new ListNode(carry);
        }

        ans = reverse(ans->next);
        return ans;
    }
};

int main()
{

    return 0;
}