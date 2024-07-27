#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void printCLL(struct Node *head){
    
    if (head == NULL){
        return;
    }

    if (head->next == head){
        cout << head->data << endl;
        return;
    }
    
    
    struct Node *ptr = head->next;
    cout << head->data << " ";
    while (ptr != head){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void printCLLTraversal(struct Node *head){
    if (head == NULL){
        return;
    }

    struct Node *ptr = head;
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr != head);
}

struct Node * createCircularLL(){
    int data[5] = {1,2,3,4,5};
    struct Node * head = new Node(data[0]);

    struct Node *ptr = head;
    for (int i = 1; i < 5; i++){
        struct Node *newNode = new Node(data[i]);

        ptr->next = newNode;
        ptr = ptr->next;
    }

    // Make it circular
    ptr->next = head;


    return head;
}

int main()
{
    struct Node * head = createCircularLL();
    
    printCLLTraversal(head);
    return 0;
}