#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool palinOrNot(int n){
    vector<int> nos;

    int temp = n;
    int res = 0;
    int count = 0;

    // Get digits of the number
    while (temp > 0){
        res = temp % 10;
        temp = temp / 10;
        nos.push_back(res);
        count++;
    }

    // Now taking two pointer approach
    int start = 0, end = count;
    int flag = 1;

    while (start <= end){
        if (nos[start] != nos[end - 1]){
            return false;
        }
        start++;
        end--;
    }

    return true;
}

bool palinOptimise(int n){
    // Reverse of the number
    int rev = 0;
    int temp = n;
    int res = 0;

    while (temp > 0){
        res = temp % 10;
        rev = rev * 10 + res;
        temp = temp / 10;    
    }


    return (rev == n);
    // Keep checking it with og no
}

int main()
{
    if (palinOptimise(27272)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}