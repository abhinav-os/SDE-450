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

bool detectLoop(Node *head)
{
    Node *slowPtr, *fastPtr;
    slowPtr = fastPtr = head;

    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if (fastPtr == slowPtr)
            return true;
    }

    return false;
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

    if (detectLoop(head))
        cout << "Loop exists.";
    else
        cout << "Loop doesn't exist";
}

/*
x denotes that last node of LL is connected to xth node. If x is 0, then no loop.
4 1
1 8 3 4
*/