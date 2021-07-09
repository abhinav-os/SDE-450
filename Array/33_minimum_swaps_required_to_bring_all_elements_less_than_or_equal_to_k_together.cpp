/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int minSwap(vector<int>& a, int k) {
    int n = a.size();
    int lessThanK = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] <= k) {
            lessThanK += 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < lessThanK; i++) {
        if(a[i] > k) {
            cnt += 1;
        }
    }

    int ans = cnt, start = 1, end = lessThanK;

    while(end < n) {
        if(a[start-1] > k && a[end] <= k)           cnt -= 1;
        else if(a[start-1] <= k && a[end] > k)      cnt += 1;

        ans = min(ans, cnt);

        start += 1;
        end += 1;
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

    cout << minSwap(a, k);
}

/*
5 3
2 1 5 6 3
*/