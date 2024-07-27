#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;

    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printDLL(struct Node *head){
    struct Node * ptr = head;

    while (ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

struct Node * createDLL(){
    vector<int> data = {1,2,3,4};

    struct Node *head = new Node(data[0]);
    struct Node *ptr = head;

    for (int i = 1; i < data.size(); i++){
        struct Node * newNode = new Node(data[i]);

        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = newNode;
    }

    return head;
}

struct Node * insertBegin(struct Node * head, int data){
    
    struct Node * newNode = new Node(data);
    
    if (head == NULL){
        return newNode;
    }

    else{
        newNode->next = head;
        head->prev = newNode;

        head = newNode;

        return head;
    }
}

struct Node * insertEnd(struct Node *head, int data){
    
    struct Node * newNode = new Node(data);
    
    if (head == NULL){
        return newNode;
    }

    else{
        struct Node *ptr;

        while (ptr->next != NULL){
            ptr = ptr->next;
        }

        newNode->prev = ptr;
        ptr->next = newNode;

        return head;
    }
}



int main()
{
    struct Node *head = createDLL();
    head = insertBegin(head, 1);
    head = insertEnd(head, 10);
    printDLL(head);

    return 0;
}