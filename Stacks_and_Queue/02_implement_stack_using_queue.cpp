#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-stack-using-queues/description/

class MyStack
{
public:
    queue<int> qu;

    MyStack()
    {
        // constructor
    }

    void push(int x)
    {
        qu.push(x);
        for (int i = 0; i < qu.size() - 1; i++)
        {
            qu.push(qu.front());
            qu.pop();
        }
    }

    int pop()
    {
        int x = qu.front();
        qu.pop();
        return x;
    }

    int top()
    {
        return qu.front();
    }

    bool empty()
    {
        return qu.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    

    return 0;
}