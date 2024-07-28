#include<iostream>
#include<bits/stdc++.h>
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

struct Node *createLinkedList()
{
    vector<int> data = {5, 10, 15, 20, 25};
    
    struct Node *head = new Node(data[0]);
    head->next = new Node(data[1]);
    head->next->next = new Node(data[2]);
    head->next->next->next = new Node(data[3]);
    head->next->next->next->next = new Node(data[4]);
    // head->next->next->next->next = head->next->next;

    return head;
}

bool detectLoop(struct Node *head){
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL && fast != slow){
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == slow){
        return true;
    }else{
        return false;
    }
}

bool detectLoopVisited(struct Node *head){
    struct Node *ptr = head;

    while (ptr != NULL){

        if (ptr->visited == true){
            return true;
        }

        ptr->visited = true;
        ptr = ptr->next;
    }
    return false;
}

int main()
{
    struct Node *head = createLinkedList();

    cout << detectLoopVisited(head);

    return 0;
}