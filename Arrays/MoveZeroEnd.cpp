#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void moveZero(vector<int>&arr){
    
    int first = 0;
    int last = arr.size() - 1;

    while (first < last) {
        if (arr[first] == 0) {
            swap(arr[first], arr[last]);
            last--;
        } else {
            first++;
        }
    }

}

int main()
{
    vector<int> ar = {24,0,0,3,0,1,24};

    moveZero(ar);

    for (int i: ar){
        cout << i << " ";
    }
    
    return 0;
}