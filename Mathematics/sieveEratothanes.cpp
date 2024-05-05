#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool isPrime(int n){
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i < n; i+=6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }

    return true;
}

// Sieve of Eratothenes
// Any number we get
// Find smaller prime numbers in range
void sieveEratothenes(int n){
    for (int i = 2; i < n; i++){
        if (isPrime(i)){
            cout << i << " ";
        }
    }
}

// Using an array
// Mark all as true
// Then mark the multiples of 2,3 and 5 as false

void sieve(int n){
    vector<bool> ar(n+1, true);

    for (int i = 4; i < n + 1; i++){
        if (i % 2 == 0 && i != 2){
            ar[i] = false;
        }else if (i % 3 == 0 && i != 3){
            ar[i] = false;
        }else if (i % 5 == 0 && i != 5){
            ar[i] = false;
        }
    }

    for (int i = 2; i < n + 1; i++){
        if (ar[i] == true){
            cout << i << " ";
        }
    }
    
}

int main()
{

    // sieveEratothenes(1113);
    sieve(20);

    return 0;
}