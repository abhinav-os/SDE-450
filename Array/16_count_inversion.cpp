/*
    Time Complexity: 
    Space Complexity: 
*/

#include <bits/stdc++.h>
using namespace std;

int countInversion(vector<int>& a) {
    int n = a.size();

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = {a[i], i};
    }

    sort(v.begin(), v.end());

    vector<bool> vis(n, false);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && v[i].first != a[i]) {
            int cnt = 0, j = i;
            while(!vis[j]) {
                cnt += 1;
                vis[j] = true;
                j = v[j].second;
            }
            if(cnt > 0)
                ans += (cnt-1);
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    } 

    cout << countInversion(a);
}

/*
5
2 4 1 3 5
*/