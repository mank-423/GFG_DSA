#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sumNaturalNumbers(int n, int k)
{
    // We want the sum
    if (n == 0){
        return k;
    }

    sumNaturalNumbers(n - 1, k + n);
}

int main()
{
    cout << sumNaturalNumbers(4, 0);
    return 0;
}