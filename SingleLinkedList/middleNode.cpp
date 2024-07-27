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

struct Node *createLinkedList(vector<int> data)
{
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

void middleNode(struct Node *head)
{
    if (head == NULL)
    {
        cout << "NULL";
    }

    if (head->next == NULL)
    {
        cout << head->data << endl;
    }

    int count = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    int temp = 0;
    ptr = head;
    while (temp != count / 2)
    {
        temp++;
        ptr = ptr->next;
    }

    cout << ptr->data << endl;
}

void middleNodeOptimise(struct Node *head){
    // We use slow and fast ptr
    struct Node * slow = head;
    struct Node * fast = head;

    // Using concept of odd and even nodes
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data << endl;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    struct Node *head = createLinkedList(data);
    middleNodeOptimise(head);
    return 0;
}