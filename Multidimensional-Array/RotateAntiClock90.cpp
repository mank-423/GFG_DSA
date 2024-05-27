#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateAntiClock90(vector<vector<int>>&matrix){
    // Reverse
    for (int i = 0 ; i < matrix.size(); i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // Tranpose it
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j <= i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    printMatrix(matrix);
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    rotateAntiClock90(matrix1);

    return 0;
}