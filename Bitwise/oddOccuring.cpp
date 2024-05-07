#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Need to find odd number of occurence number in the array
int singleOddOneOut(vector<int> ar){
    int res = ar[0];
    for (int i = 1; i < ar.size(); i++){
        res = res ^ ar[i];
    }

    return res;
}

void twoOddOneOut(vector<int> ar){
    map<int, int> mp;

    for (int i: ar){
        mp[i]++;
    }

    for (auto i : mp){
        if (i.second & 1){
            cout << i.first << " ";
        }
    }
}

void twoOddOneOutXOR(vector<int> ar){
    int res = ar[0];

    for (int i = 1; i < ar.size(); i++){
        res = res ^ ar[i];
    }

    int k = res & (~( res - 1 ));

    int res1 = 0;
    int res2 = 0;

    for (int i = 0; i < ar.size(); i++){
        if ((ar[i] & k) != 0){
            res1 = res1 ^ ar[i];
        }else{
            res2 = res2 ^ ar[i];
        }
    }

    cout << res1 << " " << res2 << endl;
}

int main()
{
    vector<int> ar = {1,1,1,2,2,3,4,4,4,4};

    // int check = singleOddOneOut(ar);
    
    // if (check == 0){
    //     cout << "No odd occurence of number";
    // }else{
    //     cout << check;
    // }

    twoOddOneOut(ar);
    
    return 0;
}