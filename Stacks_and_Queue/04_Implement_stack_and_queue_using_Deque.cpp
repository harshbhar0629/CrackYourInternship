#include <bits/stdc++.h>
using namespace std;
//

class Stack
{
    deque<int> dq;

public:
    int push(int x)
    {
        dq.push_back(x);
    }

    int pop()
    {
        if (dq.size() == 0)
        {
            return -1;
        }
        else
        {
            dq.pop_back();
        }
    }

    int top()
    {
        if (dq.size() == 0)
        {
            return -1;
        }
        else
        {
            return dq.back();
        }
    }

    bool isEmpty()
    {
        return dq.empty();
    }
};

class Queue
{
    deque<int> dq;

public:
    int push(int x)
    {
        dq.push_front(x);
    }

    int front(){
        if(dq.size() == 0){
            return -1;
        }
        return dq.back();
    }

    int pop()
    {
        if (dq.size() == 0)
        {
            return -1;
        }
        else
        {
            dq.pop_back();
        }
    }

    bool isEmpty()
    {
        return dq.empty();
    }
};

int main()
{

    return 0;
}