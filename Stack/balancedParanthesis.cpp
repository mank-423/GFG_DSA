#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool paranthesisCheck(string s){
    stack<char> check;

    if (s.length() == 0){
        return false;
    }

    // Opening paranthesis then push
    for (char c: s){
        if (c == '{' || c == '[' || c == '('){
            check.push(c);
        }
        // Closing then pop
        else{
            char top = check.top();

            if (c == '}' && top != '{'){
                return false;
            }else if (c == ')' && top != '('){
                return false;
            }
            else if (c == ']' && top != '['){
                return false;
            }

            check.pop();
        }
    }


    if (check.empty()){
        return true;
    }

}



int main()
{
    string input = "[]{([])}";

    if (paranthesisCheck(input)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}