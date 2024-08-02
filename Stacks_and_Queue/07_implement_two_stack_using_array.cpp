#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

class twoStacks
{
    vector<int> st;
    int top1, top2;

public:
    twoStacks()
    {
        top1 = -1, top2 = 105;
        st.resize(105, -1);
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        st[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        st[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        --top1;
        return st[top1 + 1];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == 105)
        {
            return -1;
        }
        top2++;
        return st[top2 - 1];
    }
};

int main(){
    

    return 0;
}