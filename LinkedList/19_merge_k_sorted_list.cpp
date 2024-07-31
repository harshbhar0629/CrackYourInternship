#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/merge-k-sorted-lists/description/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto it : lists)
        {
            if (it)
            {
                pq.push(it);
            }
        }

        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            temp->next = it;
            if (it->next)
            {
                pq.push(it->next);
            }
            temp = temp->next;
        }

        return ans->next;
    }
};

int main()
{

    return 0;
}