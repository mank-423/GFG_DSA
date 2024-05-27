#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Median of row wise sorted matrix
// Assumptions:
// i.   Odd sized matrix
// ii.  All distinct elements
int findMedianNaive(vector<vector<int>> matrix)
{
    vector<int> res;

    // Flat the matrix to array
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            res.push_back(matrix[i][j]);
        }
    }

    // Sort the array
    sort(res.begin(), res.end());

    // Find median since all odd,
    // If total = odd => (total + 1) / 2
    // If total = even => total / 2, (total / 2) + 1 => avg of both

    int n = res.size();
    int answer = 0;
    if (n & 1)
    {
        int ind = (n + 1) / 2 - 1;
        answer = res[ind];
    }
    else
    {
        int ind1 = n / 2;
        int ind2 = ind1 + 1;

        answer = (res[ind1] + res[ind2]) / 2;
    }

    return answer;
}

int findMedianOptimize(vector<vector<int>> matrix)
{
    int c = matrix[0].size();
    int r = matrix.size();
    int min = matrix[0][0];
    int max = matrix[0][c - 1];

    for (int i = 0; i < r; i++)
    {
        if (matrix[i][0] < min)
        {
            min = matrix[i][0];
        }

        if (matrix[i][c - 1] > max)
        {
            max = matrix[i][c - 1];
        }
    }

    // Use min max for the binary search
    int desired = (r * c + 1) / 2;

    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        for (int i = 0; i < r; ++i)
            place += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }

    return min;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 10, 20},
        {15, 25, 35},
        {5, 30, 40}};

    // cout << findMedianNaive(matrix);
    cout << findMedianOptimize(matrix);

    return 0;
}