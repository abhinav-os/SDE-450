/*
    Time Complexity: Worst case complexity of O(N*N); Average takes O(N);
    Space Complexity: O(1)
*/

/*
ASSUMPTION: ALL ELEMENTS ARE DISTINCT.
Modified Quick Sort to Quick Select. Pick a pivot, place it at correct position, if it's kth position, return. Else recur for ONLY ONE side.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Priority Queue approach, Time Cpmplexity: O(N+K*logN), Space Compexity: O(N)
*/

int kthSmallestUsingPriorityQueue(vector<int> &a, int k)
{
    int n = a.size();
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < n; i++)
        pq.push(a[i]);

    for (int i = 0; i < k - 1; i++)
        pq.pop();
    return pq.top();
}

int partition(vector<int> &a, int l, int r)
{
    int x = a[r], i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i += 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int kthSmallest(vector<int> &a, int k)
{
    int left = 0, right = a.size() - 1;
    while (left <= right)
    {
        int pi = partition(a, left, right);
        if (pi + 1 == k)
            return a[pi];
        else if (pi + 1 < k)
            left = pi + 1;
        else
            right = pi - 1;
    }

    return -1;
}

pair<int, int> kthMinMax(vector<int> &a, int k)
{
    int n = a.size();

    int min = kthSmallestUsingPriorityQueue(a, k);
    int max = kthSmallestUsingPriorityQueue(a, n - k + 1);

    return {min, max};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> k;

    pair<int, int> ans = kthMinMax(a, k);
    cout << ans.first << " " << ans.second;
}

/*
6
7 10 4 3 20 15
2
*/