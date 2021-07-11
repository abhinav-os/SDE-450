/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

/**
 * f(i, j) = f(i+1, j-1); if a[i] == a[j], else 
 *           1 + f(i+1, j); if a[i] < a[j], else
 *           1 + f(i, j-1); if a[i] > a[j]
 */ 

#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& a) {
    int n = a.size();
    int l = 0, r = n-1, ans = 0;
    while(l < r) {
        if(a[l] == a[r]) {
            l += 1;
            r -= 1;
        } else if(a[l] < a[r]) {
            a[l+1] += a[l];
            l += 1;
            ans += 1;
        } else {
            a[r-1] += a[r];
            r -= 1;
            ans += 1;
        }
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
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    cout << minOperations(a);
}

/*
4
1 4 5 1
*/