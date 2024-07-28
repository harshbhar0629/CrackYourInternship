#include <bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/AGGRCOW/
// https://www.spoj.com/submit/AGGRCOW/

#define ll long long int

bool isPossible(vector<ll>& c, ll k, ll m){
    ll n = c.size();
    ll last = c[0];
    ll cnt = 1;

    for (int i = 0; i<n; i++){
        if(c[i]-last >= m){
            last = c[i];
            cnt++;
        }
    }
    // cout << cnt << " ";
    return cnt >= k;
}

int solve(vector<ll>& c, ll k){
    ll n = c.size();
    sort(c.begin(), c.end());
    ll lo = 1, hi = c.back() - c[0];
    ll ans = 0;

    while(lo<=hi){
        ll m = (lo + hi) / 2;
        if(isPossible(c, k, m)){
            ans = m;
            lo = m + 1;
        }
        else{
            hi = m - 1;
        }
    }
    // cout << endl;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(a, k) << "\n";
    }

    return 0;
}