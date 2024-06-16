#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr){
    int res = 1;

    for (int i = 0; i < arr.size() - 1; i++){
        if (arr[i] >= arr[i+1]){
            res = 0;
            break;
        }
    }

    return res;
}

int main()
{
    vector<int> ar = {1,2,3,4};
    string res = isSorted(ar) ? "true" :  "false";
    cout << res;
    return 0;
}