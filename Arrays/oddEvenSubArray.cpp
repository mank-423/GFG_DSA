#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Kadanes's with condition for odd or even

int maxEvenOddSubarray(vector<int> ar){
    int maxSize = 0;
    int currSize = 0;
    int bit = (ar[0] % 2);
    int i = 0;

    if (ar.size() == 0){
        return -1;
    }

    while (i < ar.size()){
        if (ar[i] % 2 == bit){
            currSize++;
            bit = !bit;
            i++;
        }else{
            maxSize = max(maxSize, currSize);
            currSize = 0;
            bit = ar[i] % 2;
        }
    }

    maxSize = max(currSize, maxSize);

    return maxSize;
}

int main()
{   
    vector<int> ar1 = {10, 12, 14, 7, 8};
    vector<int> ar2 = {10, 12, 8, 4};
    vector<int> ar3 = {5, 10, 20, 6, 3, 8};

    cout << maxEvenOddSubarray(ar3);
    return 0;
}