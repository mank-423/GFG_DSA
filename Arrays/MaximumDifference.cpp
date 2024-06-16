#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> ar){
    int n = ar.size();

    int res = ar[1] - ar[0];
    int minVal = ar[0];

    for (int i = 1; i < n; i++){
        res = max(res, ar[i] - minVal);
        minVal = min(minVal, ar[i]);
    }

    return res;
}

int main()
{
    vector<int> ar = {40,2,1,100};

    cout << maxDiff(ar) << endl;
    return 0;
}