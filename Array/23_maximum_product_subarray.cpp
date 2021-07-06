/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

/*
Similar to largest sum contigous subarray, except the fact that maximum product can have both
maximum product value or minimum product value at that index.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maximumProduct(vector<int>& a) {
    ll n = a.size(), min_val = a[0], max_val = a[0], ans = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < 0) {
            swap(min_val, max_val);
        }
        min_val = min((ll)a[i], 1LL * a[i] * min_val);
        max_val = max((ll)a[i], 1LL * a[i] * max_val);

        ans = max(ans, max_val);
    }

    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << maximumProduct(a);
}

/*
5
6 -3 -10 0 2
*/