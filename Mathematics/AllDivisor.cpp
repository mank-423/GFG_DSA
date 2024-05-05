#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Naive
void printAllDivisor(int n)
{
    // If the no is 1
    cout << 1 << " ";

    if (n > 1)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
            }
        }
    }
    cout << n << " ";
}

// Optmization
// Divisors come in pair
// N = p * q => p, q < N
// O(n ** 1/2)
void printDivisorOptimize(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        cout << i << " ";
        if ((i != n % i) & (n % i == 0))
        {
            cout << n / i << " ";
        }
    }
}

// Sorted way of optimize
void sortedPrintDivisor(int n)
{
    int i = 0;
    for (i = 1; i * i < n; i++)
    {
        if ( n % i == 0 ){
            cout << i << " ";
        }
    }

    for (; i >= 1; i--){
        if (n % i == 0){
            cout << n / i << " ";
        }
    }
}

int main()
{
    sortedPrintDivisor(225);
    return 0;
}