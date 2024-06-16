#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxFlips(vector<int> ar){
    int maxLength = 0;
    int maxEle = -1;
    int currLength = 1;
    int currEle = 0;

    for (int i = 1; i < ar.size(); i++){
        currEle = currEle ^ ar[i];
        // If element is same we will get 0
        if (currEle == 0){
            currLength++;
        }else{
            maxLength = max(currLength, maxLength);
            maxEle = ar[i-1];
            currEle = ar[i];
            currLength = 1;
        }
    }
    maxLength = max(maxLength, currLength);
    return maxEle;
}

void optimise(vector<int> ar){
    int n = ar.size();
    int firstEle = ar[0];
    int lastEle = ar[n - 1];
    int start = 0;

    if (firstEle == lastEle){
        for (int i = 0; i < n; i++){
            if (ar[i] ^ firstEle == 1){
                start = !start;
                if (start == 1){
                    cout << "From " << i << " "; 
                }else{
                    cout << "End " << i << endl;
                }
            }
        }
    }else{
        for (int i = 0; i < n; i++){
            // Not completed
        }
    }
}

int main()
{
    vector<int> ar = {1,1,0,0,0,1,1,0,0};
    // cout << maxFlips(ar);
    optimise(ar);
    return 0;
}