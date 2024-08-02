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

struct Node * reverseLL(struct Node *head){
    Node *prev = head;
    Node *curr = prev->next;
    Node *next = NULL;
    prev->next = NULL;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

bool isPalindromeLL(struct Node *head){
    if (head == NULL){
        return true;
    }

    Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *rev = reverseLL(slow->next);

    Node *curr = head;

    while (rev != NULL){
        if (rev->data != curr->data){
            return false;
        }
        rev = rev->next;
        curr = curr->next;
    }

    return true;
}



int main()
{
    
    vector<int> data = {1, 2, 3, 2, 1};
    Node *head = createLinkedList(data);
    printLL(head);
    cout << isPalindromeLL(head) << endl;
    return 0;
}