#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

// The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


class Solution {
public:
    Node* zigZag(Node* head) {
        if(!head || !head->next){
            return head;
        }
        
        Node* curr = head;        
        bool flag = false;
        
        while(curr->next){
            if(flag){
                // true wala case >= y wala case
                if(curr->data < curr->next->data){
                    swap(curr->data, curr->next->data);
                }
            }
            else{
                if(curr->data > curr->next->data){
                    swap(curr->next->data, curr->data);
                }
            }
            flag = !flag;
            curr = curr->next;
        }
        
        return head;
    }
};

int main(){
    

    return 0;
}