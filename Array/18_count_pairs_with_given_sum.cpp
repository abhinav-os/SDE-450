/*
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int>& a, int k) {
    int n = a.size();
    unordered_map<int, int> mp;
    int ans = 0;
    mp[a[0]] += 1;
    for(int i = 1; i < n; i++) {
        ans += mp[k-a[i]];
        mp[a[i]] += 1;
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

    cout << getPairsCount(a, k);
}

/*
4 6
1 5 7 1
*/