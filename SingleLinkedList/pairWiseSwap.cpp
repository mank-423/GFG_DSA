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

struct Node * cloneLLNaive(struct Node *head){
    unordered_map<int, int> nxt;
    unordered_map<int, int> rdm;

    for (struct Node *n = head; head != NULL; head = head->next){
        if (n->next != NULL){
            nxt[n->data] = n->next->data;
        }

        if (n->random != NULL){
            rdm[n->data] = n->random->data;
        }
    }


}

int main()
{
    struct Node *head = createLinkedList();
    printLL(head);


    
    return 0;
}