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

struct Node * deleteBegin(struct Node * head){
    
    struct Node * delNode;
    
    if (head == NULL){
        return head;
    }

    if (head->next == NULL){
        delNode = head;
        return NULL;
        delete(delNode);
    }

    else{
        delNode = head;
        head = head->next;
        delete(delNode);

        return head;
    }
}

struct Node * deleteEnd(struct Node *head){
    
    struct Node * delNode;
    
    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        delNode = head;
        return NULL;
        delete(delNode);
    }

    else{
        struct Node * tmp = head;

        while (tmp->next != NULL){
            tmp = tmp->next;
        }

        delNode = tmp;

        tmp->prev->next = tmp->next;

        delete(delNode);

        return head;
    }
}



int main()
{
    struct Node *head = createDLL();
    head = deleteBegin(head);
    head = deleteEnd(head);
    printDLL(head);

    return 0;
}