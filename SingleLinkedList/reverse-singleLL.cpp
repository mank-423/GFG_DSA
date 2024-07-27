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

// Save next node
// Curr next to prev
// Prev to curr
// curr to next node saved one!
struct Node *reverseSingleLL(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *nextNode = NULL;

    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;

    return head;
}

struct Node *helper(struct Node *curr, struct Node *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    //Save the curr->next to send in the new call
    struct Node * next = curr->next;

    // Reverse the linkage
    curr->next = prev;

    return helper(next, curr);
}

struct Node *reversalRecursive(struct Node *head)
{

    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;

    return helper(curr, prev);
}

struct Node *createLinkedList()
{
    vector<int> data = {1, 2, 3, 4};
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
    printLL(head);

    // head = reverseSingleLL(head);
    head = reversalRecursive(head);
    printLL(head);

    return 0;
}