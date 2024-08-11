#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int d) : data(d), next(NULL), prev(NULL) {}
};

class Stack {
private:
    Node *head;
    Node *top;
    int topNumber;

public:
    Stack() : head(NULL), top(NULL), topNumber(-1) {}

    bool isEmpty() {
        return top == NULL;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            top = newNode;
        } else {
            newNode->prev = top;
            top->next = newNode;
            top = newNode;
        }
        topNumber++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1; // or throw an exception
        } else {
            Node *ptr = top;
            int value = ptr->data;
            top = top->prev; // Move top to previous node
            if (top != NULL) {
                top->next = NULL; // Update new top's next to NULL
            } else {
                head = NULL; // If the stack is empty now, update head
            }
            delete ptr;
            topNumber--;
            return value;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        } else {
            return top->data;
        }
    }

    int size() {
        return topNumber + 1;
    }

    void printLL() {
        Node *ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(2);
    st.push(7);
    st.push(3);
    st.printLL(); // Print stack before pop
    cout << st.pop() << endl; // Print popped value
    st.printLL(); // Print stack after pop
    return 0;
}
