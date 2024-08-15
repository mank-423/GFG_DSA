#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{

    // All operations take O(1) time
    // Used using Dequeue

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // cout << s.top() << endl;

    // s.pop();

    // cout << s.top() << endl;

    s.push(30);
    s.push(40);

    while (!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}