/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

/*
Kadane's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int largestSumSubarray(vector<int> a)
{
    int n = a.size();
    int max_so_far = a[0];
    int cur_max = a[0];

    for (int i = 1; i < n; i++)
    {
        cur_max = max(a[i], cur_max + a[i]);
        max_so_far = max(max_so_far, cur_max);
    }

    return max_so_far;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = largestSumSubarray(a);
    cout << ans;
}

/*
5
1 2 3 -2 5
*/