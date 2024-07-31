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

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = new Node();
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        return ptr;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;

    return head;
}

pair<struct Node *, struct Node *> createLinkedLists()
{
    vector<int> data1 = {1, 2, 3, 4};
    vector<int> data2 = {5, 6};
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // Create first linked list
    for (int i = 0; i < data1.size(); i++)
    {
        head1 = insertAtEnd(head1, data1[i]);
    }

    // Create second linked list
    for (int i = 0; i < data2.size(); i++)
    {
        head2 = insertAtEnd(head2, data2[i]);
    }

    // Create intersection point
    struct Node *intersection = new Node();
    intersection->data = 7;

    // Append intersection to the end of first list
    struct Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = intersection;

    // Append intersection to the end of second list
    temp = head2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = intersection;

    // Continue the linked list from the intersection point
    vector<int> intersectionData = {8, 9};
    for (int i = 0; i < intersectionData.size(); i++)
    {
        intersection = insertAtEnd(intersection, intersectionData[i]);
    }

    return {head1, head2};
}

int intersectionPoint(struct Node *h1, struct Node *h2)
{

    struct Node *ptr1 = h1;
    struct Node *ptr2 = h2;

    // case1, h1 > h2, ptr1 = null
    while (ptr1->next != NULL && ptr1 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    ptr1 = h1;
    ptr2 = h2;

    // case2, h2 > h1
    while (ptr2->next != NULL && ptr2 != NULL)
    {
        if (ptr2 == ptr2)
        {
            return ptr2->data;
        }
        ptr2 = ptr2->next->next;
        ptr1 = ptr1->next;
    }
    ptr1 = h1;
    ptr2 = h2;

    // Case 3
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return 0;
}

int intersectionPointOptimise(struct Node *h1, struct Node *h2)
{
    struct Node *ptr1 = h1;
    struct Node *ptr2 = h2;

    if (h1 == NULL || h2 == NULL)
    {
        return 0;
    }

    while (ptr1 != ptr2)
    {

        ptr1 = ptr1 == NULL ? h2 : ptr1->next;
        ptr2 = ptr2 == NULL ? h1 : ptr2->next;
    }

    return ptr1 ? ptr1->data : -1;
}

int main()
{

    pair<struct Node *, struct Node *> heads = createLinkedLists();

    cout << "First Linked List: ";
    printLL(heads.first);

    cout << "Second Linked List: ";
    printLL(heads.second);

    cout << intersectionPointOptimise(heads.first, heads.second) << endl;

    return 0;
}