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

void loopHere(Node *head, Node *tail, int pos)
{
    if (pos == 0)
        return;

    Node *walk = head;
    for (int i = 0; i < pos; i++)
        walk = walk->next;
    tail->next = walk;
}

int startingPointOfTheLoop(Node *head)
{
    Node *slowPtr, *fastPtr;
    slowPtr = fastPtr = head;

    bool flag = false;
    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (slowPtr == fastPtr)
        {
            flag = true;
            break;
        }
    }

    if (!flag)
        return -1;

    slowPtr = head;
    while (fastPtr != slowPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    return slowPtr->data;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, x, num;
    cin >> n >> x >> num;

    Node *head, *tail;
    head = tail = newNode(num);

    for (int i = 1; i < n; i++)
    {
        cin >> num;
        tail->next = newNode(num);
        tail = tail->next;
    }

    loopHere(head, tail, x);

    cout << startingPointOfTheLoop(head);
}

/*
A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.
*/