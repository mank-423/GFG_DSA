#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void printLL(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

struct Node *createLinkedList(vector<int> data)
{
    int n = data.size();
    struct Node *head = new Node(data[0]);
    struct Node *ptr = head;

    for (int i = 1; i < n; i++)
    {
        struct Node *newNode = new Node(data[i]);
        ptr->next = newNode;
        ptr = newNode;
    }

    return head;
}

void getNthNodeEnd(struct Node *head, int posEnd){
    if (head == NULL){
        cout << " ";
    }

    int count = 0;

    struct Node *ptr = head;
    while (ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    if (count > posEnd){
        cout << " ";
    }

    int posFromFront = count - posEnd;
    ptr = head;
    count = 0;
    while (count != posFromFront){
        count++;
        ptr = ptr->next;
    }

    cout << ptr->data << endl;
}

void getNthNodeEndOptimise(struct Node *head, int pos){
    struct Node *first = head;
    struct Node *second = head;

    for (int i = 0; i < pos; i++){
        first = first->next;
        if (first == NULL){
            cout << "Got position more than the length";
            return;
        }
    }

    while (first != NULL){
        second = second->next;
        first = first->next;
    }

    cout << second->data << endl;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5, 6};
    struct Node *head = createLinkedList(data);
    getNthNodeEndOptimise(head, 3);
    return 0;
}