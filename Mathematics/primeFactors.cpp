#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Logic -> Divisors exist in pair, N can be written as multiplication of powers of prime factors
bool isPrime(int n){
    if (n == 1) return false;
    if (n == 2 || n== 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i < n; i+=6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

void isPrimeFactor(int n){
    
    for (int i = 2; i*i <=n; i++){
        if (isPrime(i) && (n % i == 0)){
            cout << i << " ";
        }
    }
    cout << endl;
}


// The idea is first run it from 2 to root n
// Find a prime factor, divide it unitl possible
// Keep printing and then next no
void isPrimeOptimized(int n){
    if (n <= 1) return;

    for (int i = 2; i*i <= n; i++){
        while ((n % i) == 0){
            cout << i << " ";
            n = n / i;
        }
    }

    if (n > 1){
        cout << n << " ";
    }
}

// Removing iterations of 2 and 3
void isPrimeMoreOptimized(int n){
    if (n <= 1) return;
    while (n % 2 == 0){
        cout << "2" << " ";
        n = n / 2;
    }while (n % 3 == 0){
        cout << "3" << " ";
        n = n / 3;
    }

    for (int i = 5; i*i <= n; i+=6){
        while ((n % i) == 0){
            cout << i << " ";
            n = n / i;
        }
        while (n %(i+2) == 0){
            cout << i+2 << " ";
            n = n / (i + 2);
        }
    }

    if (n > 1){
        cout << n << " ";
    }
}

int main()
{
    isPrimeMoreOptimized(56);
    return 0;
}