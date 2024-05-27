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

vector<vector<int>> transponse(vector<vector<int>> matrix){
    vector<vector<int>> newMatrix;

    for (int i = 0; i < matrix.size(); i++){
        vector<int> temp;
        for (int j = 0; j < matrix[0].size(); j++){
            temp.push_back(matrix[j][i]);
        }
        newMatrix.push_back(temp);
    }

    return newMatrix;
}

void tranposeOptimize(vector<vector<int>> &matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int>> result;
    tranposeOptimize(matrix);

    printMatrix(matrix);
    return 0;
}