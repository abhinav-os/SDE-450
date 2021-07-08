/*
    Time Complexity: O(N+M)
    Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i]] += 1;
    }

    for(int i = 0; i < m; i++) {
        if(mp[b[i]] == 0) {
            return false;
        }

        mp[b[i]] -= 1;
    }

    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)      cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++)      cin >> b[i];
    
    if(isSubset(a, b)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

/*
6
11 1 13 21 3 7
4
11 3 7 1
*/