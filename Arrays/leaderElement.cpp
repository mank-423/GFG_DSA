#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getLeader(vector<int> arr)
{
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << "i " << i << endl;
        if (arr[i] > arr[i + 1])
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                // cout << "j " << j << endl;
                if (arr[i] <= arr[j])
                {
                    break;
                }

                // If reached last element
                if (j == arr.size() - 1)
                {
                    res.push_back(arr[i]);
                }

                // Last element
                if (i == j)
                {
                    res.push_back(arr[i]);
                }
            }
        }
    }

    return res;
}

vector<int> leaderOptimise(vector<int> arr){
    vector<int> res;
    int n = arr.size();
    res.push_back(arr[n - 1]);
    
    int max = arr[n - 1];

    for (int i = n - 2; i >= 0; i--){
        if (arr[i] > max){
            max = arr[i];
            res.push_back(max);
        }
    }

    return res;
}

int main()
{
    vector<int> ip = {30, 20, 10};

    vector<int> res = leaderOptimise(ip);

    for (int i : res){
        cout << i << endl;
    }

    return 0;
}