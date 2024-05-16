#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char initial, char aux, char target){
    if (n == 0){
        return;
    }
    towerOfHanoi(n - 1, initial, target, aux);
    cout << "Moving disc " << n << " from " << initial << " to " << target << endl;
    towerOfHanoi(n - 1, aux, initial, target);
}

int main()
{
    towerOfHanoi(4, 'A', 'B', 'C');
    return 0;
}