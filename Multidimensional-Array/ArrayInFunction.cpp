#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int ar[3][2]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}
// No way to generalize the rows and columns
void printGeneralised(int **ar, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

// Best, as it can grow and shrink
// Cache disadvantgae, not stored at contigous memory location.
void printGeneralVector(vector<vector<int>>&ar, int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < ar[i].size(); j++){
            cout << ar[i][j] << " ";
        }
    }
}

int main()
{
    int ar[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    // printGeneralised(**ar);
    return 0;
}