#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> ar = {10, 10, 10, 9};

    int max = 0, maxInd = -1;
    int second = 0, secondInd = -1;

    for (int i = 0; i < ar.size(); i++){
        if (ar[i] > max){
            maxInd = i;
            max = ar[i];
        }
    }
    cout << ar[maxInd] << endl;

    for (int i = 0; i < ar.size(); i++){
        if (ar[i] < max && ar[i] > second){
            second = ar[i];
            secondInd = i;
        }
    }

    cout << secondInd << endl;

    return 0;
}