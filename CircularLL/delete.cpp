#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void printCLLTraversal(struct Node *head){
    if (head == NULL){
        return;
    }

    struct Node *ptr = head;
    do{
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr != head);
    cout << endl;
}

struct Node * createCircularLL(){
    vector<int> data = {1,2,3,4,5};
    struct Node * head = new Node(data[0]);

    struct Node *ptr = head;
    for (int i = 1; i < data.size(); i++){
        struct Node *newNode = new Node(data[i]);

        ptr->next = newNode;
        ptr = ptr->next;
    }

    // Make it circular
    ptr->next = head;


    return head;
}

struct Node * deleteBegin(struct Node *head){
    if (head == NULL){
        return head;
    }

    if (head->next == head){
        delete(head);
        return NULL;
    }

    else{
        struct Node *delNode = head;
        struct Node *ptr = head;
        do{
            ptr = ptr->next;
        }while (ptr->next != head);
        ptr->next = head->next;
        head = head->next;
        delete(delNode);
    }
    return head;
}

struct Node * deleteBeginOptimise(struct Node *head){
    if (head == NULL){
        return head;
    }

    if (head->next == head){
        delete(head);
        return NULL;
    }

    else{
        struct Node *delNode = head->next;
        
        int t = head->next->data;
        head->data = t;
        
        head->next = head->next->next;

        delete(delNode);
    }
    return head;
}

struct Node *deleteKNode(struct Node *head, int k){
    if (head == NULL){
        return head;
    }

    if (k == 0){
        return head;
    }

    if (k == 1){
        delete(head);
        return NULL;
    }

    else{
        int count = 1;
        struct Node *prev = NULL;
        struct Node *curr = head;
        do{
            prev = curr;
            curr = curr->next;
            count++;
        }while(count != k && curr != head);

        if (curr == head){
            return head;
        };

        prev->next = curr->next;
        delete(curr);

        return head;
    }
}

int main()
{
    struct Node * head = createCircularLL();
    
    printCLLTraversal(head);

    // head = deleteBeginOptimise(head);

    head = deleteKNode(head, 3);

    printCLLTraversal(head);
    return 0;
}