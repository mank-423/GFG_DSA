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

struct Node *sortedInsert(struct Node *head, int data)
{

    struct Node *newNode = new Node(data);
    struct Node *ptr = head;
    struct Node *prev = NULL;

    if (head == NULL)
    {
        return NULL;
    }

    if (data < head->data)
    {
        newNode->next = head;
        head = newNode;
    }

    else
    {
        while (ptr->next != NULL && data > ptr->data)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (data > ptr->data)
        {
            ptr->next = newNode;
        }
        else
        {
            prev->next = newNode;
            newNode->next = ptr;
        }
    }

    return head;
};

struct Node *createLinkedList()
{
    vector<int> data = {5, 10, 15, 20};
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

int main()
{
    struct Node *head = createLinkedList();
    printLL(head);

    head = sortedInsert(head, 27);

    printLL(head);
    return 0;
}