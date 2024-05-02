#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int ip = n;

    int count = 0;

    while (ip > 0){
        ip = ip / 10;
        count++;
    }

    return count;
}

int main()
{
    int n, res;

    cout << "Enter a number: ";
    cin >> n;
    
    res = countDigits(n);

    cout << res << endl;
    return 0;
}