#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/partition-list/description/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *newHead = new ListNode(0);
        ListNode *tempH = newHead;
        ListNode *high = new ListNode(0);
        ListNode *temp = head, *tempHigh = high;

        while (temp)
        {
            if (temp->val < x)
            {
                tempH->next = temp;
                tempH = tempH->next;
            }
            else
            {
                tempHigh->next = temp;
                tempHigh = tempHigh->next;
            }
            temp = temp->next;
        }

        tempHigh->next = NULL;
        tempH->next = high->next;
        return newHead->next;
    }
};

int main()
{

    return 0;
}