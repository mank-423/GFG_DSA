#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Every no written as sum of power of 2
// Traverse through all bits of a number in logn time

// while n > 0, if n % 2 != 0 (bit is 1); else (bit is 0)
// E.g. - 3 ^ 10; 10 = 1 0 1 0
// We know 3 ^ 10 = 3 ^ 8 * 3 ^ 2
// And if we multiply the bits with 3 = 3 ^ 4 (1) + 3 ^ 3 (0) + 3 ^ 2 (1) + 3 ^ 1 (0)

int iterativePower(int x, int n){
    int res = 1;

    while (n > 0){
        // Optimizing here
        // We can use n & 1 = used to check if n is odd or not
        if (n % 2 == 0){ 
            res = res * x;
        }
        x = x * x;

        // We can do n = n >> 1;
        n = n / 2;
    }

    return res;
}

int main()
{
    iterativePower(3, 10);
    return 0;
}