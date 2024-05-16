#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void generateSubset (string x, string curr, int i){

    // Start with empty string, curr
    // Then either we include it or we don't
    if (i == x.length()){
        cout << curr << " ";
        return;
    }

    generateSubset(x, curr, i + 1);
    generateSubset(x, curr + x[i], i + 1);
    // Everytime we increase n

}


int main()
{
    string x = "ABC";
    string curr = "";
    int n = 0;
    generateSubset(x, curr, n);

    return 0;
}