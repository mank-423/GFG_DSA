#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Take a and b
// Start by comparing the shorter no with greater (a > b)
// We check a % b == 0, so return a
// Else we check from 1 .. b for greatest common divisor
int gcd(int a, int b){
    int n1 = max(a, b);
    int n2 = min(a, b);

    int gcd = 1;

    if (n2 % n1 != 0){
        for (int i = n1; i > 0; i--){
            if (n1 % i == 0 && n2 % i == 0){
                gcd = max(gcd, i);
            }
        }
    }else{
        gcd = n1;
    }

    return gcd;
}

int main()
{
    cout << gcd(2406, 654);
    return 0;
}