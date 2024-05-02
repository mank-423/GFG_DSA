#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int res = 1;

    for (int i = 2; i <= n; i++){
        res *= i;
    }

    return res;
}

int recurFactorial(int n){

    if (n == 1){
        return 1;
    }

    return n * recurFactorial(n - 1);


}

int main()
{   
    cout << recurFactorial(5);
    return 0;
}