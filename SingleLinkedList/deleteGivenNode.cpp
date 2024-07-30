#include <iostream>
#include <bits/stdc++.h>
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

struct Node *createLinkedList()
{
    vector<int> data = {5, 10, 15, 20, 25};
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

// The ptr will never be the last node
void *deleteGivenNode(struct Node *ptr)
{
    struct Node *t1 = ptr;

    // Copy data of next pointer
    t1->data = t1->next->data;
    struct Node *delNode = t1->next;
    t1->next = t1->next->next;
    delete(delNode);
}

int main()
{
    struct Node *head = createLinkedList();
    printLL(head);
    deleteGivenNode(head->next->next);
    printLL(head);

    return 0;
}