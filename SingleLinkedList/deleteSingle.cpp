#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
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


struct Node *deleteFirst(struct Node *head){
    if (head == NULL){
        return NULL;
    }

    struct Node *delNode = head;
    head = head->next;
    delete(delNode);
    return head;
}

struct Node *deleteLast(struct Node *head){
    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        delete head;
        return NULL;
    }

    struct Node *ptr = head;

    while (ptr->next->next != NULL){
        ptr = ptr->next;
    }

    struct Node *delNode = ptr->next;
    ptr->next = NULL;
    delete(delNode);

    return head;

}


struct Node *createLinkedList()
{
    vector<int> data = {1, 2, 3, 4};
    int n = data.size();
    struct Node *head = new Node();
    struct Node *ptr = new Node();
    ptr = head;

    for (int i = 0; i < data.size(); i++)
    {
        if (i < n - 1)
        {
            struct Node *ptr1 = new Node();
            ptr->data = data[i];
            ptr->next = ptr1;
            ptr = ptr1;
        }
        else
        {
            ptr->data = data[i];
            ptr->next = NULL;
        }
    }

    return head;
}

int main()
{

    struct Node *head = createLinkedList();
    printLL(head);

    printLL(deleteLast(head));

    return 0;
}