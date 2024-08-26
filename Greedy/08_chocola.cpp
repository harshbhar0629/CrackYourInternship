#include <bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/CHOCOLA/

int solve(vector<int> &v, vector<int> &h)
{
    int n = v.size();
    int m = h.size();
    int ans = 0, vr = 1, hr = 1;
    int i = 0, j = 0;

    sort(v.begin(), v.end(), greater<int>());
    sort(h.begin(), h.end(), greater<int>());

    while (i < n and j < m)
    {
        if (v[i] >= h[j])
        {
            ans += v[i] * hr;
            i++;
            vr++;
        }
        else
        {
            ans += h[j] * vr;
            j++;
            hr++;
        }
    }

    while (i < n)
    {
        ans += v[i] * hr;
        i++;
    }

    while (j < m)
    {
        ans += h[j] * vr;
        j++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n - 1), h(m - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> v[i];
        }

        for (int j = 0; j < m - 1; j++)
        {
            cin >> h[j];
        }
        cout << solve(v, h) << "\n";
    }

    return 0;
}