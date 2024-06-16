#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> arPrefix;

void createPrefix(vector<int> ar){
    int curr = 0;
    for (int i = 0; i < ar.size(); i++){
        // Add  
        curr += ar[i];
        arPrefix.push_back(curr);
    }
}

int getSum(int first, int last){
    int n = arPrefix.size();
    if (first == 0){
        return arPrefix[n - 1];
    }

    return arPrefix[last] - arPrefix[first - 1];
}


int getWSum(int first, int last){
    
}

int main()
{

    vector<int> ar = {2,8,3,9,6,5,4};
    createPrefix(ar);
    cout << getSum(2, 4);
    return 0;
}
