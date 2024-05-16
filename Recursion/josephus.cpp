#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int josephusProblem(int n, int k)
{
    vector<int> ar(n, 0);

    int count = 0;
    int temp = 1;
    int tempCounter = 1;
    while (count != n - 1)
    {
        if (temp % n == 0)
        {
            temp = 1;
            tempCounter++;
            continue;
        }
        if (tempCounter == 3 && ar[temp] != 1)
        {
            ar[temp] = 1;
            cout << temp << endl;
            count++;
            tempCounter = 0;
        }

        temp++;
        tempCounter++;
    }

    // Check for survivor
    int i;
    for (i = 1; i <= n; i++)
    {
        if (ar[i] == 0)
        {
            break;
        }
    }

    return i - 1;
}

int jos(int n, int k){
    if (n == 1){
        return 0;
    }

    return (jos(n-1, k) + k) % n ;
}

int main()
{
    cout << jos(5, 3);
    return 0;
}