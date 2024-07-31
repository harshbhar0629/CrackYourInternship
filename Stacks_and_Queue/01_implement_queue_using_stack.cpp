#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue
{
public:
    stack<int> st;
    MyQueue()
    {
        // constructor
    }

    void push(int x)
    {
        stack<int> temp;

        while (st.size() > 0)
        {
            temp.push(st.top());
            st.pop();
        }

        temp.push(x);

        while (temp.size() > 0)
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    int pop()
    {
        int x = st.top();
        st.pop();
        return x;
    }

    int peek()
    {
        return st.top();
    }

    bool empty()
    {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    

    return 0;
}