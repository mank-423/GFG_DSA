#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Element greater on left
// Closest to current element and greatest

// We will use stock span procedure

// 1. We will check if stack is empty then put -1 to the array
// 2. How stack can be empty?? If top of element is not greater than current -> we keep popping elements
// 3. If top is greater than curr -> put it to array -> push the curr to stack
vector<int> prvsGreaterElement(vector<int> arr){
    stack<int> s;
    vector<int> res;

    s.push(arr[0]);
    res.push_back(-1);

    for (int i = 1; i < arr.size(); i++){
        if (arr[i] <= s.top()){
            res.push_back(s.top());
            s.push(arr[i]);
        }else{
            while (!s.empty() && arr[i] > s.top()){
                s.pop();
            }

            if (s.empty()){
                res.push_back(-1);
                s.push(arr[i]);
            }else{
                res.push_back(s.top());
                s.push(arr[i]);
            }
        }
    }

    return res;

}


int main()
{
    // vector<int> input = {15, 10, 18, 12, 4, 6, 19, 8};
    vector<int> input = {12, 10, 8};
    vector<int> res = prvsGreaterElement(input);

    for (int i: res){
        cout << i << " ";
    }
    return 0;
}