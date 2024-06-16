#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSumSubArrayK(vector<int> ar, int k){
    int first = 0;
    int last = k;
    int currSum = 0;
    int maxSum = INT_MIN;
    int n = ar.size();

    if (n < k){
        return -1;
    }
    
    // First finding sum of a window
    for (int i = 0; i < k; i++){
        currSum += ar[i];
    }

    if (n == k){
        return currSum;
    }

    maxSum = max(currSum, maxSum);

    for (int i = k; i < n; i++){
        currSum += ar[i] - ar[i - k];
        maxSum = max(currSum, maxSum);
    }

    return maxSum;

}

int main()
{
    vector<int> ar = {10, 5, -2, 20, 1};

    cout << maxSumSubArrayK(ar, 3);
    return 0;
}