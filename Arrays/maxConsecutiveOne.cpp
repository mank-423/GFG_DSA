#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> ip){
    int n = ip.size();

    int res = 0;
    int curr = 0;

    for (int i = 0; i < n; i++){
        if (curr == curr + ip[i]){
            res = max(curr, res);
            curr = 0;
        }

        curr += ip[i];
    }

    return res;
}


int main()
{
    vector<int> ip = {1,0,1,1,1,1,0,1,1};

    cout << maxLen(ip) << endl;
    return 0;
}