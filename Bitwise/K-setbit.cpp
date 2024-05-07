#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkifKBitSet(int n, int k){
    int x = n;

    x = x >> k - 1;

    return (x & 1);
}

int main()
{
    if (checkifKBitSet(10, 3)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}