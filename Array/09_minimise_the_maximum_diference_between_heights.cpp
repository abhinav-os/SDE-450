/*
    Time Complexity: O(N * log N)
    Space Complexity: O(1)
*/

/*
In the sorted array, it's best if we do +k +k .... -k -k -k.
We just have to find at which point gives minimum difference.
For minimum, we can have two options, a[0]+k, a[i+1]-k
For maximum, we can have two options, a[i]+k, a[n-1]-k
*/

#include <bits/stdc++.h>
using namespace std;

int minDifference_NegativeHeightAllowed(vector<int> a, int k)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = a.back() - a[0];

    for (int i = 0; i < n - 1; i++)
    {
        int mini = min(a[0] + k, a[i + 1] - k);
        int maxi = max(a[i] + k, a[n - 1] - k);

        ans = min(ans, maxi - mini);
    }

    return ans;
}

int minDifference_NegativeHeightNotAllowed(vector<int> a, int k)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int index = lower_bound(a.begin(), a.end(), k) - a.begin();
    int ans = a.back() - a[0];

    for (int i = index - 1; i < n - 1; i++)
    {
        int mini = min(a[0] + k, a[i + 1] - k);
        int maxi = max(a[i] + k, a[n - 1] - k);

        ans = min(ans, maxi - mini);
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << minDifference_NegativeHeightAllowed(a, k) << "\n";
    cout << minDifference_NegativeHeightNotAllowed(a, k) << "\n";
}

/*
5
10
8 1 5 4 7 5 7 9 4 6
*/