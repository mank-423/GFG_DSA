#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr){
    int n = arr.size();
    
    if (n == 1){
        return;
    }
    
    for (int i = 0; i <  n / 2; i++){
        swap(arr[i], arr[n - i - 1]);
    }
}

int main()
{
    vector<int> arr = {1};

    reverseArray(arr);

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}