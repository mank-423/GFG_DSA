#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int trailZeroesFactorial(int n){
    
    //Find the factorial
    long long int fact = 1;
    for (int i = 2; i <= n; i++){
        fact = fact * i;
    }

    // Find trailing zeroes
    int count = 0;
    while (fact % 10 == 0){
        count++;
        fact = fact / 10;
    }

    return count;
}


// We need to find 5 and 2 as prime factor of nos which make 10
// We can observe that no of 2 > no of 5, so only need to find 5

// Gives count of 5's in prime Factors
int primeFactor5(int n){
    int temp = n;

    int count = 0;

    while (temp > 0){
        if (temp % 5 != 0){
            break;
        }
        temp = temp / 5;
        count++;
    }
    return count;
}


int trailZeroesFactorialOptimize(int n){
    int temp = n;
    int res = 0;
    for (int i = 5; i <= n; i+=5){
        res += primeFactor5(i);
    }
    return res;
}


// Check nos divisble by 5
// Check nos divisible by 25 .... and so on
// And thus we can get the exact no of 5

// O( logn )
int countTrailingZeroes(int n){
    int count = 0;

    for (int i = 5; i <= n; i*=5){
        count += n / i;
    }

    return count;
}

int main()
{
    cout << trailZeroesFactorialOptimize(100);
    return 0;
}