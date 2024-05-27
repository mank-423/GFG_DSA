#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binSearch(vector<int> arr, int key, int low, int high)
{
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] == key){
            return true;
        }
        else if (arr[mid] > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return false;
}

bool findElementInMatrix(vector<vector<int>> &matrix, int key)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int i = 0;
    for (i = 0; i < r; i++)
    {
        if (matrix[i][0] <= key && matrix[i][c - 1] >= key){
            break;
        }
    }

    return binSearch(matrix[i], key, 0, c - 1);
}

int main()
{
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    int key = 22;

    cout << findElementInMatrix(matrix, key);

    return 0;
}