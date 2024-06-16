#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> ar = {1,2,44,5,6};

    int maxInd = 0;

    for (int i =0; i < ar.size(); i++){
        if (ar[i] > ar[maxInd]){
            maxInd = i;
        }
    }

    cout << ar[maxInd] << endl;
    return 0;
}