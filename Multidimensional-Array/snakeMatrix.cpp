#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void snakePrint(vector<vector<int>> &m)
{
    int r = m.size();
    int c = m[0].size();
    // (0,0),
    for (int i = 0; i < r; i++)
    {
        // Even
        if (i % 2 == 0 || i == 0)
        {
            for (int j = 0; j < c; j++)
            {
                cout << m[i][j] << " ";
            }
        }
        // Odd
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                cout << m[i][j] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    snakePrint(matrix);

    return 0;
}