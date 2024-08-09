#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution{
    unordered_map<Node*, Node*>childToParent;
    void setParent(Node* root, Node*& targetA, int a){
        queue<Node*>qu;
        qu.push(root);
        
        while(!qu.empty()){
            auto curr = qu.front(); qu.pop();
            if(curr->data == a){
                targetA = curr;
            }
            if(curr->left){
                qu.push(curr->left);
                childToParent[curr->left] = curr;
            }
            if(curr->right){
                qu.push(curr->right);
                childToParent[curr->right] = curr;
            }
        }
    }
    
public:
    int findDist(Node* root, int a, int b) {
        Node* targetA;
        setParent(root, targetA, a);
        unordered_map<Node*, int>vis;
        
        queue<pair<Node*, int>>qu;
        vis[targetA]++;
        qu.push({targetA, 0});
        
        while(!qu.empty()){
            auto curr = qu.front(); qu.pop();
            if(curr.first->data == b){
                return curr.second;
            }
            
            if(curr.first->left and !vis[curr.first->left]){
                vis[curr.first->left]++;
                qu.push({curr.first->left, curr.second +1});
            }
            
            if(curr.first->right and !vis[curr.first->right]){
                vis[curr.first->right]++;
                qu.push({curr.first->right, curr.second +1});
            }
            
            if(childToParent[curr.first] and !vis[childToParent[curr.first]]){
                vis[childToParent[curr.first]]++;
                qu.push({childToParent[curr.first], curr.second +1});
            }
        }
        return 0;
    }
};


int main(){
    

    return 0;
}