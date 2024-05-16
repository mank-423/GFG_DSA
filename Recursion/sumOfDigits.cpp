#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int sumOfDigits(int n, int temp){
    if (n == 0 ){
        return temp;
    }
    temp += n % 10;
    n = n / 10;
    return sumOfDigits(n, temp);
}

int main()
{
    cout << sumOfDigits(9987, 0);
    return 0;
}