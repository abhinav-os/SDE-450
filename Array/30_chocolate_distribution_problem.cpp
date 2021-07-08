/*
    Time Complexity: O(N*logN)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = INT_MAX;

    for(int i = k-1; i < n; i++) {
        ans = min(ans, a[i] - a[i - k + 1]);
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << findMinDiff(a, k);
}

/*
8 5
3 4 1 9 56 7 9 12
*/