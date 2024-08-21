#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

#define ll long long int
class Solution
{
    vector<vector<char>> numbers = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};
    vector<pair<int, int>> dir = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {0, 0}};
    ll dp[30][5][5];

    ll f(int n, int i, int j)
    {
        if (n == 1)
        {
            return 1;
        }
        if (dp[n][i][j] != -1)
        {
            return dp[n][i][j];
        }

        ll ans = 0;
        for (int d = 0; d < 5; d++)
        {
            int ni = i + dir[d].first;
            int nj = j + dir[d].second;
            if (ni < 0 || ni >= 4 || nj < 0 || nj >= 3 || (ni == 3 and nj != 1))
            {
                continue;
            }
            ans += f(n - 1, ni, nj);
        }

        return dp[n][i][j] = ans;
    }

public:
    ll getCount(int n)
    {
        ll ans = 0;
        memset(dp, -1, sizeof dp);

        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (numbers[i][j] >= '0' and numbers[i][j] <= '9')
                {
                    ans += f(n, i, j);
                }
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}