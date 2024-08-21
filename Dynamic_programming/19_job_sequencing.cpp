#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


class Solution
{
    static bool cmp(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxSize = 0;
        for (int i = 0; i < n; i++)
        {
            maxSize = max(maxSize, arr[i].dead);
        }

        vector<int> sequence(maxSize + 1, -1);
        int cnt = 0, profit = 0;

        for (int i = 0; i < n; i++)
        {
            int id = arr[i].id;
            int p = arr[i].profit;
            int dead = arr[i].dead;
            for (int d = dead; d > 0; d--)
            {
                if (sequence[d] == -1)
                {
                    cnt++;
                    sequence[d] = id;
                    profit += p;
                    break;
                }
            }
        }

        return {cnt, profit};
    }
};

int main(){
    

    return 0;
}