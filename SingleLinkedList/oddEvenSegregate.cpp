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

struct Node *segregate(struct Node *head){
    struct Node *ptr = head;

    for (struct Node *n = head; n != NULL; n = n->next){
        if ((n->data) % 2 == 0){
            int x = n->data;
            int y = ptr->data;

            n->data = y;
            ptr->data = x;

            ptr = ptr->next;
        }
    }

    return head;
}

struct Node *segregateOddEven(struct Node *head){
    struct Node *ptr = head;
    struct Node *os = NULL, *oe = NULL;
    struct Node *es = NULL, *ee = NULL;

    for (struct Node *n = head; n != NULL; n = n->next){
        if ((n->data) % 2 == 0){
            if (es == NULL){
                es = ee = n;
            }
            else{
                ee->next = n;
                ee = ee->next;
            }
        }else{
            if (os == NULL){
                os = oe = n;
            }
            else{
                oe->next = n;
                oe = oe->next;
            }
        }
    }

    if (os == NULL || es == NULL){
        return head;
    }

    ee->next = os;
    oe->next = NULL;

    return es;
}


int main()
{
    struct Node *head = createLinkedList();
    printLL(head);
    head = segregateOddEven(head);
    printLL(head);

    return 0;
}