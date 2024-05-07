#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    if (n == 0){
        return 0; 
    }else if (n == 1){
        return 0;
    }else if (n == 2){
        return 1;
    }

    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}

// Optimized solution
// Divisors always exist in pair 65 = (65, 1), (13, 5) ....
// x * y = n
// if x <= y, x * x <= n, x <= (n)**1/2

// Traverse till square root of n
bool isPrimeOptimized(int n){
    if (n == 1) return false; // 1 then return false
    // This will remove many iterations in for loop
    else if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    // This is for starting check
    else if (n == 2 || n == 3 ){
        return true;
    }

    // Earlier only one change i * i < n
    // Now this for loop
    for (int i = 5; i*i <= n; i+=6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }

    return true;
}

int main()
{
    int res = isPrimeOptimized(25);

    if (res == 1){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }

    return 0;
}