#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *random;

    Node(int d)
    {
        data = d;
        next = NULL;
        random = NULL;
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

struct Node *createLinkedList()
{
   
    struct Node *head = new Node(6);
    struct Node *ptr1 = new Node(10);
    struct Node *ptr2 = new Node(15);
    struct Node *ptr3 = new Node(20);
    struct Node *ptr4 = new Node(25);

    head->next = ptr1;
    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr4;
    ptr4->next = NULL;


    head->random = ptr2;
    ptr2->random = head;
    ptr1->random = ptr3;
    ptr3->random = ptr2;
    ptr4->random = ptr3;

    return head;

}

Node * cloneLL(Node *head){
    if (head == NULL){
        return head;
    }

    unordered_map<Node *, Node *> map;

    for (Node *curr = head; curr != NULL; curr = curr->next){
        map[curr] = new Node(curr->data);
    }

    for (Node *curr = head; curr != NULL; curr = curr->next){
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
    }

    return map[head];

}

int main()
{
    struct Node *head = createLinkedList();
    Node *h2 = cloneLL(head);
    printLL(h2);

    
    
    return 0;
}