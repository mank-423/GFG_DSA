#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpanBruteForce(vector<int> input){
    vector<int> res;

    for (int i = 0; i < input.size(); i++){
        int count = 1;

        for (int j = i - 1; j >= 0 && input[j] <= input[i]; j--){
            count++;
        }

        res.push_back(count);
    }

    return res;
}

vector<int> stockSpanProblem(vector<int> input){
    
    vector<int> res;
    stack<int> s;

    s.push(0);
    res.push_back(1);

    for (int i = 1; i < input.size(); i++){
        while (s.empty() == false && input[s.top()] <= input[i]){
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top();
        res.push_back(span);
        s.push(i);
    }

    return res;
}

int main()
{
    vector<int> input = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    vector<int> r = stockSpanProblem(input);
    
    for (int x: r){
        cout << x << " " << endl;
    }
    return 0;
}