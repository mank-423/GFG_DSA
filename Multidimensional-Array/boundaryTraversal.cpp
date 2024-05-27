#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void boundaryTraversal(vector<vector<int>>&ar){
    int r = ar.size();
    int c = ar[0].size();

    int count = 0;
    int j = 0, k = 0;


    for (int i = 0; i < 4; i++){
        count++;
        if (count == 1){
            for (j = 0; j < c; j++){
                cout << ar[k][j] << " ";
            }
            k++;
        }
        else if (count == 2){
            j--;
            k++;
            for (; k < r; k++){
                cout << ar[k][j] << " ";
            }
        }
        else if (count == 3){
            k--;
            j--;
            for ( ; j >= 0; j--){
                cout << ar[k][j] << " ";
            }
        }
        else{
            j++;
            k--;
            for (; k > 0; k--){
                cout << ar[k][j] << " ";
            }
        }
    }
}

void boundaryTraverseMatrix(vector<vector<int>>&matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    if (r == 1){
        for (int i = 0; i < c; i++){
            cout << matrix[0][i] << " ";
        }
    }
    else if (c == 1){
        for (int i = 0; i < r; i++){
            cout << matrix[i][0] << " ";
        }
    }
    else{
        // L -> R
        for (int i = 0; i < c; i++){
            cout << matrix[0][i] << " ";
        }

        //R -> Down
        for (int i = 1; i < r; i++){
            cout << matrix[i][c - 1] << " ";
        }

        // R -> L
        for (int i = c - 2; i >= 0; i--){
            cout << matrix[r - 1][i] << " ";
        }

        // B -> T
        for (int i = r - 2; i >= 1; i--){
            cout << matrix[i][0] << " ";
        }


    }
        
    
    


}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
    };

    boundaryTraverseMatrix(matrix);
    return 0;
}