#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void deleteElement(vector<int> &arr, int index){
    for (int i = index; i < arr.size(); i++){
        arr[i] = arr[i+1];
    }
}

int CheckForDups(vector<int> &arr){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == arr[i+1]){
            deleteElement(arr, i);
            count++;
        }
    }

    return count - 1;
}

void checkForDuplicatesArray(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size()){
        if (arr[i] == arr[i+1]){
            arr.erase(arr.begin() + i);        
        }
        else{
            i++;
        }
    }
}

int optimize(vector<int>&arr){
    int count = 1;

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] != arr[count - 1]){
            arr[count] = arr[i];
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> ip = {1,2,3,3,4,5,5,6};

    // checkForDuplicatesArray(ip);

    int res = optimize(ip);

    for (int i = 0; i < res; i++){
        cout << ip[i] << " ";
    }

    // for (int i = 0; i < ip.size(); i++){
    //     cout << ip[i] << " ";
    // }
    return 0;
}