#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(vector<int> ar, int curr, int i, int target){
    if (i == ar.size()){
        return (curr == target) ? 1 : 0;
    }

    if (curr == target){
        return 1;
    }

    if (curr > target){
        return 0;
    }

    return countSubsetSum(ar, curr, i+1, target) + countSubsetSum(ar, curr+=ar[i], i+1, target);
}

int main()
{
    vector<int> ar = {10, 5, 2, 3, 6};
    // ar, khaali array, 
    cout << countSubsetSum(ar, 0, 0, 8);
    return 0;
}