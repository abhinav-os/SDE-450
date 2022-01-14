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

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

Node *reverse(Node *head, int k)
{
    Node *newHead = NULL;
    Node *head2 = head;

    for (int i = 0; i < k && head != NULL; i++)
    {
        Node *nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }

    if (head != NULL)
        head2->next = reverse(head, k);
    return newHead;
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
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);

    print(head);

    int k;
    cin >> k;

    Node *head1 = reverse(head, k);
    print(head1);
}

/*

*/