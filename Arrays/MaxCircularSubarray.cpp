#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxCircularSubarray(vector<int> ar)
{
    int n = ar.size();
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = 0; j < n; j++)
        {
            int index = (i + j) % n;
            currSum += ar[index];

            if (currSum > maxSum)
            {
                maxSum = currSum;
            }
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int kadane(vector<int> ar) {
    int maxSum = ar[0];
    int curr = ar[0];
    for (int i = 1; i < ar.size(); i++) {
        curr = max(ar[i], curr + ar[i]);
        maxSum = max(maxSum, curr);
    }
    return maxSum;
}

// Find min sum subarray, total - minSum = circular
int optimise(vector<int> ar){
    
    int normalMax = kadane(ar);

    // All elements are negative
    if (normalMax < 0){
        return normalMax;
    }

    int arr_sum = 0;

    for (int i = 0; i < ar.size(); i++){
        arr_sum += ar[i];
        ar[i] = -ar[i];
    }

    int max_circular = arr_sum + kadane(ar);

    return max(max_circular, normalMax);
}

int main()
{
    vector<int> ar = {-5, -2};
    cout << optimise(ar);
    return 0;
}