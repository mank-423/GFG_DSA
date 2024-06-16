#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map<int, int> freqSortedArray(vector<int>&ip){
    map<int, int> res;

    for (int i : ip){
        res[i]++;
    };

    return res;
}

int main()
{
    vector<int> ip = {10,2,23,4,23,2};
    map<int, int> res = freqSortedArray(ip);

    for (auto i : res){
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}