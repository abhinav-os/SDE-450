/*
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int> a) {
    vector<int> b(a);
    reverse(b.begin(), b.end());
    return b;
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

    vector<int> result = reverseArray(a);
    for(int ele : result) {
        cout << ele << " ";
    }
}

/*
5
1 2 3 4 5
*/