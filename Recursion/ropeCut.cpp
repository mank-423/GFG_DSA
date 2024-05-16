#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ropeCutProblem(int n, int a, int b, int c){

    if (n < 0){
        return -1;
    }

    if (n == 0){
        return 0;
    }
    
    int res = max(ropeCutProblem(n - a, a, b, c), max(ropeCutProblem(n - b, a, b, c), ropeCutProblem(n - c, a, b, c)));

    if (res == -1){
        return -1;
    }

    return res + 1;
}

int main()
{
    cout << ropeCutProblem(9, 2, 2, 2);
    return 0;
}