#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1


struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        int start = 0, petrol = 0, deficiency = 0;

        for (int i = 0; i < n; i++)
        {
            petrol += p[i].petrol;
            if (petrol < p[i].distance)
            {
                deficiency += p[i].distance - petrol;
                start = i + 1;
                petrol = 0;
            }
            else
            {
                petrol -= p[i].distance;
            }
        }
        if (petrol >= deficiency)
        {
            return start;
        }

        return -1;
    }
};

int main(){
    

    return 0;
}