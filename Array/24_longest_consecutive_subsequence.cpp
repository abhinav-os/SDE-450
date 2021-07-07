/*
    Time Complexity: 
    Space Complexity: 
*/

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(vector<int>& a) {
    int n = a.size();

    unordered_set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s.find(a[i]-1) == s.end()) {
            int cur = 1, temp = a[i];
            while(s.find(temp + 1) != s.end()) {
                cur += 1;
                temp += 1;
            }
            ans = max(ans, cur);
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

    cout << findLongestConseqSubseq(a);
}

/*
7
2 6 1 9 4 5 3
*/