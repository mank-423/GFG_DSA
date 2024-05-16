#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printRecurOppsotie(int n){

    if (n == 0){
        return;
    }

    cout << n << " ";
    printRecurOppsotie(n - 1);
}

void printRecur(int n){
    if (n == 0){
       return;
    }
    printRecur(n-1);
    cout << n << " ";
}



int main()
{
    printRecurOppsotie(10);
    cout << endl;
    printRecur(10);
    return 0;
}