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

Node *createLL(vector<int> data)
{
    struct Node *head = new Node(data[0]);
    struct Node *ptr = head;

    for (int i = 1; i < data.size(); i++)
    {
        struct Node *p1 = new Node(data[i]);
        ptr->next = p1;
        ptr = ptr->next;
    }

    return head;
}

struct Node *mergeSorted(struct Node *h1, struct Node *h2)
{

    struct Node *head = new Node(0);
    struct Node *p1 = h1;
    struct Node *p2 = h2;

    // Set the head
    if (p1->data < p2->data)
    {
        head->data = p1->data;
        p1 = p1->next;
    }
    else
    {
        head->data = p2->data;
        p2 = p2->next;
    }

    Node *ptr = head;
    while (p1 != NULL && p2 != NULL)
    {
        Node *temp = new Node(0);

        if (p1->data < p2->data)
        {
            temp->data = p1->data;
            p1 = p1->next;
        }
        else
        {
            temp->data = p2->data;
            p2 = p2->next;
        }

        ptr->next = temp;
        ptr = temp;
    }

    // Insert left over elements
    while (p1 != NULL){
        Node *temp = new Node(0);
        temp->data = p1->data;
        ptr->next = temp;
        ptr = temp;
        p1 = p1->next;
    }while (p2 != NULL){
        Node *temp = new Node(0);
        temp->data = p2->data;
        ptr->next = temp;
        ptr = temp;
        p2 = p2->next;
    }

    return head;
}

int main()
{
    Node *h1 = createLL({1, 4, 10, 20});
    Node *h2 = createLL({3, 12, 24});

    printLL(h1);
    printLL(h2);

    Node *head = mergeSorted(h1, h2);
    printLL(head);

    return 0;
}