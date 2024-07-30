#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorder-list/description/

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* reverse(ListNode* curr){
        ListNode* prev= NULL ;
        ListNode* after =curr;

        while(after!=NULL){
            after = after->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;

    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* temp = reverse(curr);
        slow->next = NULL;
        fast=slow=head;

        while(fast!= NULL and temp!=NULL){
            curr = temp->next;
            fast = fast->next;
            temp->next = fast;
            slow->next = temp;
            slow = fast;
            temp = curr;
        }    
    }
};

int main(){
    

    return 0;
}