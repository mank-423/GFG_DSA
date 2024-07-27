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

struct Node *removeDuplicate(struct Node *head){

    if (head == NULL || head->next == NULL){
        return head;
    }

    struct Node *curr = head->next;
    struct Node *prev = head;
    struct Node *delNode;

    while (curr != NULL){
        
        if (prev->data == curr->data){
            delNode = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(delNode);
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

struct Node *helper(struct Node *curr, struct Node *head){
    if (curr == NULL){
        return head;
    }

    if (curr->data == curr->next->data){
        struct Node *delNode = curr->next;
        curr = curr->next;
        delete(delNode);
    }

    return helper(curr->next, head);
}

struct Node *recursiveRemoveDuplicate(struct Node *head){
    struct Node *delNode;
    struct Node *curr = head;

    return helper(curr, head);    
}

int main()
{
    vector<int> data = {10, 10, 20, 20, 30, 40, 50, 60, 60};
    struct Node *head = createLinkedList(data);
    head = removeDuplicate(head);
    printLL(head);
    return 0;
}