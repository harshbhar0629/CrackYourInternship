#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getMax(int arr[], int n)
    {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    // A function to do counting sort of arr[]
    // according to the digit represented by exp.
    void countSort(int arr[], int n, int exp)
    {

        // Output array
        int output[n];
        int i, count[10] = {0};

        // Store count of occurrences
        for (i = 0; i < n; i++){
            count[(arr[i] / exp) % 10]++;
        }

        for (i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }

        // Build the output array
        for (i = n - 1; i >= 0; i--){
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // numbers according to current digit
        for (i = 0; i < n; i++){
            arr[i] = output[i];
        }
    }

    void radixsort(int arr[], int n){

        // Find the maximum number to know number of digits
        int m = getMax(arr, n);

        // Do counting sort for every digit.
        for (int exp = 1; m / exp > 0; exp *= 10){
            countSort(arr, n, exp);
        }
    }
};

int main(){
    

    return 0;
}