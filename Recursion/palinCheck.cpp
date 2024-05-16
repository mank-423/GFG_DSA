#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isPalinCheck(string x, int first, int last){
    if (first >= last){
        return true;
    }


    if (x[first] != x[last]){
        return false;
    }
    
    return isPalinCheck(x, first+1, last - 1);
}

// abcaa 0 5
// bcb   1 4



int main()
{
    string temp = "abcba";
    int n = 5;

    cout << isPalinCheck(temp, 0, n -  1);

    return 0;
}