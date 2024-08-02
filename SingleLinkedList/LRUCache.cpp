#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
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

bool hit(unordered_map<int, int> *mp, int data)
{
    if (mp->find(data) != mp->end())
    {
        return true;
    }
    else
    {
        (*mp)[data] = 1;
        return false;
    }
}

struct Node* operation(struct Node* head, int data, int &currSpace, int limitSize, bool hit) {
    if (hit) {
        struct Node* ptr = head;

        // Find the node with the same data
        while (ptr != NULL && ptr->data != data) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            return head; // Node not found (shouldn't happen if hit is true)
        }

        // Remove ptr from its current position
        if (ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        } else {
            // ptr is the head node
            head = ptr->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }

        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }

        // Add node to the front
        ptr->next = head;
        if (head != NULL) {
            head->prev = ptr;
        }
        ptr->prev = NULL;
        head = ptr;
    } else {
        // Add the node
        struct Node* newNode = new Node(data);
        
        if (limitSize <= currSpace) {
            // Delete the last node
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            if (temp->prev != NULL) {
                temp->prev->next = NULL;
            } else {
                // The list had only one node
                head = NULL;
            }
            delete temp;
            currSpace--;
        }

        // Add the new node to the front
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        currSpace++;
    }

    return head;
}


struct Node *lruCacheDesign(vector<int> input, unordered_map<int, int> *mp, int sizeLimit)
{
    int count = 1;
    struct Node *head = new Node(input[0]);
    struct Node *ptr = head;
    (*mp)[input[0]] = 1;

    for (int i = 1; i < input.size(); i++)
    {
        // hit or miss?
        bool hitDetail = hit(mp, input[i]);
        head = operation(head, input[i], count, sizeLimit, hitDetail);
        printLL(head);
    }

    return head;
}

int main()
{
    unordered_map<int, int> mp;
    vector<int> input = {10, 20, 10, 30, 40, 50, 30, 40, 60, 30};
    int sizeLimit = 4;

    struct Node *head = lruCacheDesign(input, &mp, sizeLimit);

    printLL(head);

    return 0;
}