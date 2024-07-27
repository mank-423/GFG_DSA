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

int searchRecursiveSingleLL(struct Node * ptr, int key, int pos = 1){
    if (ptr == NULL){
        return -1;
    }

    if (ptr->data == key){
        return pos;
    }

    searchRecursiveSingleLL(ptr->next, key, pos+1);
}

int searchIterativeSingleLL(struct Node *head, int data, int count = 1)
{
    struct Node *ptr = head;

    if (head == NULL)
    {
        return -1;
    }

    if (head->next == NULL)
    {
        return (head->data == data);
    }

    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            return count;
        }
        ptr = ptr->next;
        count=count+1;
    }

    return -1;
}

struct Node *createLinkedList()
{
    vector<int> data = {1, 2, 3, 4, 10, 100};
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
    struct Node *ptr = head;
    printLL(head);

    int res = searchRecursiveSingleLL(ptr, 22);
    cout << res;

    return 0;
}