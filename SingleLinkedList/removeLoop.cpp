#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    bool visited;
    Node(int d)
    {
        data = d;
        next = NULL;
        visited = false;
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

struct Node *createLinkedList() {
    vector<int> data = {5, 10, 15, 20, 25};

    struct Node *head = new Node(data[0]);
    struct Node *second = new Node(data[1]);
    struct Node *third = new Node(data[2]);
    struct Node *fourth = new Node(data[3]);
    struct Node *fifth = new Node(data[4]);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;  // End of the list

    return head;
}


struct Node *removeLoop(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->next == head)
    {
        head->next = NULL;
    }
    
    else
    {
        unordered_map<int, int> mp;
        struct Node *ptr = head;
        while (ptr != NULL){
            if (mp.find(ptr->next->data) != mp.end()){
                ptr->next = NULL;
                break;
            }
            mp[ptr->data]++;
            ptr = ptr->next;
        }
    }

    return head;
}

// Detect loop using Floyd's warhsell algo
// Move slow to the begining of the LL, and keep fast at meeting point of slow and fast
// Now move slow and fast one by one-> the point where they meet is the first Node of loop

// Q1. Find the length of the loop
// Q2. Find the first node of the loop.

int main()
{
    struct Node *head = createLinkedList();
    head = removeLoop(head);

    printLL(head);

    return 0;
}