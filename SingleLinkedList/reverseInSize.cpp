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

struct Node *reversebyK(struct Node *head, int k)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL){
        // Every time the new piece of k comes
        // We need the end next of head as rest_head;
        Node *rest_head = reversebyK(next, k);
        head->next = rest_head;
    }

    return prev;
}

int main()
{
    struct Node *head = createLinkedList();
    printLL(head);
    head = reversebyK(head, 3);
    printLL(head);

    return 0;
}