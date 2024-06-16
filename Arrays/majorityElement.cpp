#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> ar){
    // Moore's voting algorithm
    int candidate = 0;
    int votes = 0;
    int count = 0;

    for (int i = 0; i < ar.size(); i++){
        if (votes == 0){
            candidate = ar[i];
            votes++;
        }else{
            if (candidate == ar[i]){
                votes++;
            }else{
                votes--;
            }
        }
    }

    //We will find the candidate element
    for (int i = 0; i < ar.size(); i++){
        if (ar[i] == candidate){    
            count++;
        }
    }

    if (count > ar.size() / 2 ){
        return candidate;
    }else{
        return -1;
    }
}

int main()
{
    vector<int> ar = {8,7,6,8,7,6};
    cout << majorityElement(ar);
    return 0;
}