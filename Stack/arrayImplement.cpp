#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    private:
        int top = -1;
        vector<int> arr;

    public:
        void push(int x)
        {
            top++;
            arr.push_back(x);
        }

        int peek()
        {
            return arr[top];
        }

        int size(){
            return top + 1;
        }

        void pop(){
            if (top == -1){
                cout << "Undeflow error" << endl;
            }
            arr.pop_back();
            top--;
        }

        void printStack(){
            for (int i: arr){
                cout << i << " ";
            }
            cout << endl;
        }
};

int main()
{
    Stack st;

    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout << st.peek();
    
    return 0;
}