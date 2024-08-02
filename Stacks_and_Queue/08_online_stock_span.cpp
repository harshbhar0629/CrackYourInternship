#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/online-stock-span/

class StockSpanner
{
    stack<pair<int, int>> st;
    int cnt;

public:
    StockSpanner()
    {
        cnt = 0;
    }

    int next(int price)
    {

        int ans = 1;
        while (!st.empty() and st.top().first <= price)
            st.pop();
        if (!st.empty())
        {
            ans = cnt - st.top().second;
        }
        else
        {
            ans = cnt + 1;
        }

        st.push({price, cnt});
        cnt++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    

    return 0;
}