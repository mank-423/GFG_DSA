#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generatePermutation(string x, int i = 0){
    if (i == x.length() - 1){
        cout << x << " ";
    }

    
    for (int j = i; j < x.length(); j++){
        swap(x[i], x[j]);
        generatePermutation(x, i + 1);
        swap(x[i], x[j]);
    }

}


int main()
{
    string ar = "ABC";
    int height = 0;

    generatePermutation(ar, height);

    return 0;
}