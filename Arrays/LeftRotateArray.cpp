#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &ar)
{
    int i = 0;
    int n = ar.size() - 1;

    if (n == 0)
    {
        return;
    }

    swap(ar[0], ar[n]);

    for (int i = 1; i <= (n - 1) / 2; i++)
    {
        swap(ar[i], ar[n - i]);
    }
}

void rotateRight(vector<int> &ar)
{
    int n = ar.size();
    for (int i = 0; i < n; i++)
    {
        swap(ar[i], ar[n - 1]);
    }
}

void leftRotateByN(vector<int> &arr, int k)
{

    int n = arr.size();

    // If k is greater than n
    k = k % n;

    // Reverse the array
    reverse(arr.begin(), arr.end());
    // Reverse from 0 to k - 1
    reverse(arr.begin(), arr.begin() + k);
    // reverse from k to n
    reverse(arr.begin() + k, arr.end());
}

int main()
{

    vector<int> ar = {1, 2, 3, 4, 5};

    // leftRotate(ar);

    // rotateRight(ar);

    leftRotateByN(ar, 2);

    for (int i : ar)
    {
        cout << i << " ";
    }

    return 0;
}