#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr)
{
    stack<int> s;
    vector<int> res;
    int n = arr.size();
    s.push(arr[n - 1]);
    res.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {

        if (arr[i] < s.top())
        {
            res.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            while (!s.empty() && arr[i] >= s.top())
            {
                s.pop();
            }

            if (s.empty()){
                res.push_back(-1);
            }else{
                res.push_back(s.top()); 
            }

            s.push(arr[i]);
        }
    }

    reverse(res.begin(), res.end());

    return res;

}

int main()
{
    vector<int> arr = {5, 15, 10, 8, 6, 12, 9, 18};
    vector<int> res = nextGreaterElement(arr);

    for (int i: res){
        cout << i << " ";
    }
    return 0;
}