#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

class Solution
{
    int f(int i, vector<int> &v, int *arr, const int &n, const int &target)
    {
        if (i == n)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[j] != target)
                {
                    return false;
                }
            }
            return true;
        }

        for (int k = 0; k < v.size(); k++)
        {
            if (v[k] + arr[i] > target)
                continue;
            int j = k - 1;
            while (j >= 0)
            {
                if (v[j] == v[k])
                    break;
                j -= 1;
            }
            if (j != -1)
                continue;

            v[k] += arr[i];
            if (f(i + 1, v, arr, n, target))
                return true;
            v[k] -= arr[i];
        }

        return false;
    }

public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if (k == 1)
        {
            return true;
        }

        int total = 0, maxi = a[0];
        for (int i = 0; i < n; i++)
        {
            total += a[i];
            maxi = max(maxi, a[i]);
        }

        if (total % k != 0 || total / k < maxi)
            return false;

        vector<int> v(k, 0);
        sort(a, a + n);
        return f(0, v, a, n, total / k);
    }
};

int main(){
    

    return 0;
}