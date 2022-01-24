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
    return temp;
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

Node *removeDuplicates(Node *head)
{
    Node *newHead = NULL;
    while (head != NULL && head->next != NULL && head->data == head->next->data)
        head = head->next;

    newHead = head;
    Node *prev = head;
    head = head->next;

    while (head != NULL && head->next != NULL)
    {
        if (head->data == head->next->data)
            head = head->next;
        else
        {
            prev->next = head;
            prev = head;
            head = head->next;
        }
    }

    prev->next = head;

    return newHead;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, num;
    cin >> n >> num;

    Node *head, *tail;
    head = tail = newNode(num);

    for (int i = 1; i < n; i++)
    {
        cin >> num;
        tail->next = newNode(num);
        tail = tail->next;
    }

    print(head);
    Node *newHead = removeDuplicates(head);
    print(newHead);
}

/*

*/