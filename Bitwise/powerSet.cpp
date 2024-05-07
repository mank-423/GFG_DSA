#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int powerSet(string s){
    int n = s.length();

    int total = 1 << n;

    for (int i = 0; i < total; i++){
        for (int j = 0; j < n; j++){
            if (i & (1 << j) != 0){
                cout << s[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    powerSet("abc");
    return 0;
}