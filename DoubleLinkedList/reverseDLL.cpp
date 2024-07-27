#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;

    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void printDLL(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

struct Node *createDLL()
{
    vector<int> data = {1, 2, 3, 4, 5};

    struct Node *head = new Node(data[0]);
    struct Node *ptr = head;

    for (int i = 1; i < data.size(); i++)
    {
        struct Node *newNode = new Node(data[i]);

        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = newNode;
    }

    return head;
}

struct Node *reverseDLL(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    else
    {

        struct Node *front = head;
        struct Node *back = head;

        while (back->next != NULL)
        {
            back = back->next;
        }

        while (front != back && front->prev != back)
        {
            int f = front->data;
            front->data = back->data;
            back->data = f;

            front = front->next;
            back = back->prev;
        }

        return head;
    }
}

struct Node * reverseDLLNodes(struct Node *head){
    struct Node * curr = head;
    struct Node * tmp = curr->next;

    while (curr != NULL){
        curr->next = curr->prev;
        curr->prev = tmp;

        if (tmp == NULL){
            head = curr;
        }

        curr = tmp;

        if (curr != NULL){
            tmp = tmp->next;
        }
    }

    return head;
}

int main()
{
    struct Node *head = createDLL();
    head = reverseDLLNodes(head);
    printDLL(head);

    return 0;
}