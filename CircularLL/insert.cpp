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

void printCLLTraversal(struct Node *head){
    if (head == NULL){
        return;
    }

    struct Node *ptr = head;
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr != head);
    cout << endl;
}

struct Node * createCircularLL(){
    vector<int> data = {1,2,3,4,5};
    struct Node * head = new Node(data[0]);

    struct Node *ptr = head;
    for (int i = 1; i < data.size(); i++){
        struct Node *newNode = new Node(data[i]);

        ptr->next = newNode;
        ptr = ptr->next;
    }

    // Make it circular
    ptr->next = head;


    return head;
}

struct Node * insertBegin(struct Node *head, int data){
    struct Node *newNode = new Node(data);

    if (head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    if (head->next == head){
        newNode->next = head;
        head->next = newNode;
        head = newNode;
    }

    else{
        struct Node *ptr;

        newNode->next = head;

        while (ptr->next != head){
            ptr = ptr->next;
        }

        ptr->next = newNode;

        head = newNode;
    }

    return head;
}


struct Node * insertBeginOptimise(struct Node *head, int data){
    struct Node *newNode = new Node(data);

    if (head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    if (head->next == head){
        newNode->next = head;
        head->next = newNode;
        head = newNode;
    }

    else{

        // We are entering new node to 2nd position
        newNode->next = head->next;
        head->next = newNode;

        // And then swap the data of first and second ptr
        int t = head->data;
        head->data = newNode->data;
        newNode->data = t;
    }

    return head;
}


struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *newNode = new Node(data);

    if (head == NULL){
        newNode->next = newNode;
        head = newNode;        
    }

    if (head->next == NULL){
        head->next = newNode;
        newNode->next = head;
    }


    else{
        struct Node * ptr = head;

        do{
            ptr = ptr->next;
        }while(ptr->next != head);

        ptr->next = newNode;
        newNode->next = head;
    }

    return head;
}


struct Node * insertAtEndOptimise(struct Node *head, int data){
    struct Node *newNode = new Node(data);

    if (head == NULL){
        newNode->next = newNode;
        head = newNode;        
    }

    if (head->next == NULL){
        head->next = newNode;
        newNode->next = head;
    }

    else{
        // Insert new element at 2nd position
        newNode->next = head->next;
        head->next = newNode;

        // Swap first and second element
        int t = newNode->data;
        newNode->data = head->data;
        head->data = t;

        // Now we move the head;

        head = head->next;
    }

    return head;
}


int main()
{
    struct Node * head = createCircularLL();
    
    printCLLTraversal(head);

    head = insertBeginOptimise(head, 10);
    // head = insertAtEnd(head, 100);
    head = insertAtEndOptimise(head, 100);

    printCLLTraversal(head);
    return 0;
}