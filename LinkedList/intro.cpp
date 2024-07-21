#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void printLL(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void printRecurLL(struct Node *ptr)
{
    if (ptr != NULL){
        cout << ptr->data << endl;
        printRecurLL(ptr->next);
    }
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
        }else{
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
    printRecurLL(ptr);
    return 0;
}