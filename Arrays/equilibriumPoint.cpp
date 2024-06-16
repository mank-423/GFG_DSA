#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prefixSum;
vector<int> suffixSum;

void createSum(vector<int> ar){
    int curr = 0;
    int last = 0;
    int n = ar.size();
    prefixSum.resize(n);
    suffixSum.resize(n);
    for (int i = 0; i < n; i++){
        curr += ar[i];
        last += ar[n - 1 - i];
        prefixSum[i] = curr;
        suffixSum[n - 1 - i] = last;
    }
}

bool isEquilibrium(vector<int> ar){
    int n = ar.size();
    for (int i = 1; i < n - 1; i++){
        if (prefixSum[i - 1] == suffixSum[i + 1]){
            return true;
        }
    }
    return false;
}

int main()
{   
    vector<int> ar = {3, 4, 8, 9, 9, 7};
    createSum(ar);
    cout << (isEquilibrium(ar) ? "Equilibrium exists" : "No equilibrium") << endl;
    return 0;
}
