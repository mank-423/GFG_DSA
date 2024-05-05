#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int lcm(int a, int b){
    int n1 = min(a, b);
    int n2 = max(a, b);

    if (n2 % n1 == 0){
        return n2;
    }else{
        int mul = n1 * n2;
        int diff = n2 - n1;
        return mul / diff;
    }
}

// O(log(min(a,b)))
int gcdOptimized(int a, int b){
    if (b == 0){
        return a;
    }
    return gcdOptimized(b, a % b);
}


// a * b = gcd(a,b) * lcm(a , b)
// O(log(min(a,b)))
int lcmOptimized(int a, int b){
    int gcd = gcdOptimized(a, b);
    return (a * b) / gcd;
}

int main()
{
    cout << lcmOptimized(3, 7);
    return 0;
}