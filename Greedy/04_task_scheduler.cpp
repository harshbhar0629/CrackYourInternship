#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/task-scheduler/

class Solution
{
public:
    int leastInterval(vector<char> &arr, int n)
    {

        vector<int> v(26, 0);
        int maxFreq = 0, countFreq = 0;
        int size = arr.size();

        for (int i = 0; i < size; i++)
        {
            v[arr[i] - 'A']++;
            if (maxFreq < v[arr[i] - 'A'])
            {
                maxFreq = v[arr[i] - 'A'];
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (v[i] == maxFreq)
                countFreq++;
        }

        int totalTime = countFreq + (n + 1) * (maxFreq - 1);
        return max(totalTime, size);
    }
};

int main(){
    

    return 0;
}