#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/flatten-nested-list-iterator/description/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    vector<int> flatten;
    int idx;

    vector<int> flattenList(vector<NestedInteger> &nestedList)
    {
        vector<int> res;
        for (auto it : nestedList)
        {
            if (it.isInteger())
            {
                res.push_back(it.getInteger());
            }
            else
            {
                auto subList = flattenList(it.getList());
                res.insert(res.end(), subList.begin(), subList.end());
            }
        }

        return res;
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        this->idx = 0;
        flatten = flattenList(nestedList);
    }

    int next()
    {
        return flatten[idx++];
    }

    bool hasNext()
    {
        return idx < flatten.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{

    return 0;
}