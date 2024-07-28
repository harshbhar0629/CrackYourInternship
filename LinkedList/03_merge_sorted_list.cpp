#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *tempA, ListNode *tempB)
    {
        ListNode *ans = new ListNode(10);
        ListNode *tempC = ans;

        while (tempA != NULL and tempB != NULL)
        {

            if (tempA->val <= tempB->val)
            {
                tempC->next = tempA;
                tempC = tempC->next;
                tempA = tempA->next;
            }

            else
            {
                tempC->next = tempB;
                tempC = tempC->next;
                tempB = tempB->next;
            }
        }

        if (tempA != NULL)
        {
            tempC->next = tempA;
        }
        else
        {
            tempC->next = tempB;
        }

        return ans->next;
    }
};

int main()
{

    return 0;
}