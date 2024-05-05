#include<iostream>
#include<bits/stdc++.h>


using namespace std;


int power(int x, int n){
    int res = x;
    for (int i = 1; i < n; i++){
        res *= x;
    }
    
    return res;
}

// Efficient
// if = n is even we can do power(x, n/2) * power(x, n/2)
// else = n is odd, power(x, n - 1);
int powerRecur(int x, int n){
    if (n == 0){
        return 1;
    }

    if (n % 2 != 0){
        return x * power(x, n - 1);
    }else{
        return power(x, n / 2) * power(x, n / 2);
    }
}

int main()
{
    cout << powerRecur(25, 2);
    return 0;
}