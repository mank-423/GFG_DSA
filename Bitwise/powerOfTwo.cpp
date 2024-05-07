#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool powerOfTwo(int n){
   

    for (int i = 0; i < n; i++){
        int res = 1;
        res = res << i;

        if (res == n){
            return true;
        } 
    }

    return false;
}

// Observation: Count of set bits is always 1
bool checkPowerOfTwoOptimize(int n){
    int res = 0;
    // Brian Kerning algorithm
    while (n > 0){
        n = n & (n - 1);
        res += 1;
    }

    if (res == 1){
        return true;
    }else{
        return false;
    }
}

int main()
{

    if (checkPowerOfTwoOptimize(4)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return 0;
}