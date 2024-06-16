#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxSumSubarray(vector<int> ar){
    int curr = 0;
    int maxSum = 0;

    for (int i = 0; i < ar.size(); i++){
        if (curr + ar[i] <= 0){
            maxSum = max(curr, maxSum);
            curr = 0;
        }else{
            curr += ar[i];
        }
    }

    maxSum = max(maxSum, curr);

    return maxSum;
}

int maxSumSubArray(vector<int> ar){
    int res = ar[0];
    int maxEnding = ar[0];

    for (int i = 1; i < ar.size(); i++){
        maxEnding = max(maxEnding + ar[i], ar[i]);
        res = max(res, maxEnding);
    }

    return res;
}

int main()
{
    // vector<int> ar = {2,3,-8,7,-1,2,3};

    vector<int> ar = {-5,1,-2,3,-1,2,-2};
    cout << maxSumSubarray(ar); 
    return 0;
}