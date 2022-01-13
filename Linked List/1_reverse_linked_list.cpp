/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int key)
{
    Node *temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node *iterativeReverse(Node *head)
{
    Node *newHead = NULL;
    while (head != NULL)
    {
        Node *nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }

    return newHead;
}

Node *recursiveReverse(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    Node *rest = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);

    printList(head);
    // Node *newHead = iterativeReverse(head);
    Node *newHead = recursiveReverse(head);

    printList(newHead);
}

/*

*/