#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/permutations-in-array1747/1

class Solution {
public:
bool isPossible(long long a[], long long b[], int n, long long k)
{

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (a[i] + b[i] < k)
        {
            return false;
        }
    }

    return true;
}
}
;

int main(){
    

    return 0;
}