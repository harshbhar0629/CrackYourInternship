#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
public:
    Node *compute(Node *head){
        head = reverse(head);
        Node* prev = head, *curr = head->next;
        
        while(curr){
            if(curr->data >= prev->data){
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        head = reverse(head);
        
        return head;
    }
    
};

int main(){
    

    return 0;
}