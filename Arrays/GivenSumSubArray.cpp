#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Using sliding window for this
bool isSumInSubArray(vector<int> ar, int sum, int k){
    int n = ar.size();
    int curr = 0;
    if (k > n){
        return -1;
    }
    // Find sum for one window
    for (int i = 0; i < k; i++){
        curr += ar[i];
    }

    for (int i = k; i < n; i++){
        curr = curr + ar[i] - ar[i - k];

        if (curr == sum){
            return true;
        }
    }

    return false;
}


bool isExist(vector<int> ar, int sum){
    for (int i = 1; i < ar.size(); i++){
        if (isSumInSubArray(ar, sum, i)){
            return true;
        }
    }

    return false;
}

bool isOptimise(vector<int> ar, int sum){
    int curr = 0;
    int slow = 0;
    int fast = 0;

    while (fast < ar.size()){

        // if sum is equal to curr
        if (curr == sum){
            return true;
        }

        // Add to curr
        curr = curr + ar[fast];
        
        // If greater than sum, we need to make it small
        if (curr > sum){
            curr = curr - ar[slow++];
        }else{
            fast++;
        }
    }

    return false;
}

int main()
{
    vector<int> ar = {1,4, 20, 3, 10, 5};
    int sum = 5;
    cout << isOptimise(ar, sum);
    return 0;
}