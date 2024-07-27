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


struct Node * insertAtBegin(struct Node * head, int data){
    struct Node * ptr = new Node();
    ptr->data = data;

    if (head == NULL){
        ptr = head;
        return ptr;
    }

    ptr->next = head;
    head = ptr;

    return head;    
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = new Node();
    struct Node * temp = head;
    ptr->data = data;

    if (head == NULL){
        ptr = head;
        return ptr;
    }

    while (temp -> next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node * insertAtPosition(struct Node *head, int pos, int data){
    struct Node * ptr = new Node();
    ptr->data = data;

    if (pos == 0){
        ptr->next = head;
        head = ptr;
    }

    if (head == NULL){
        head = ptr;
    }

    else{
        int count = 1;
        struct Node * temp = head;
        while (count != pos){
            temp = temp->next;
            count++;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }

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

    head = insertAtBegin(head, 10);
    printLL(head);

    head = insertAtEnd(head, 100);
    printLL(head);

    head = insertAtPosition(head, 2, 200);
    printLL(head);

    return 0;
}